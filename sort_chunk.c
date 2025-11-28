/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:43:37 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/28 23:18:06 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int *stack_to_array(t_stack *a, int len)
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return NULL;
	while (a && i < len)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return arr;
}

/* int comparator for qsort */
static int int_cmp(const void *p, const void *q)
{
	int a = *(const int *)p;
	int b = *(const int *)q;
	return (a > b) - (a < b);
}

/* Helper: does stack contain any value in [minv,maxv]? */
static int stack_contains_in_range(t_stack *stack, int minv, int maxv)
{
	while (stack)
	{
		if (stack->value >= minv && stack->value <= maxv)
			return 1;
		stack = stack->next;
	}
	return 0;
}

/* Helper: find index (0-based) of first element in stack within [minv,maxv], or -1 */
static int index_of_first_in_range(t_stack *stack, int minv, int maxv)
{
	int idx = 0;
	while (stack)
	{
		if (stack->value >= minv && stack->value <= maxv)
			return idx;
		stack = stack->next;
		idx++;
	}
	return -1;
}

/* Helper: rotate A to bring element at index idx to top with minimal moves */
static void rotate_a_to_index(t_stack **a, int idx)
{
	int len = stack_size(*a);
	if (idx <= len / 2)
	{
		while (idx-- > 0)
			ra(a);
	}
	else
	{
		int moves = len - idx;
		while (moves-- > 0)
			rra(a);
	}
}

/* Push all values in [minv,maxv] from A to B.
   Heuristic: after pb, if pushed value < mid, rotate B to push it toward bottom. */
static void push_chunk_range(t_stack **a, t_stack **b, int minv, int maxv)
{
	while (stack_contains_in_range(*a, minv, maxv))
	{
		int idx = index_of_first_in_range(*a, minv, maxv);
		if (idx < 0)
			break;
		rotate_a_to_index(a, idx);
		/* now top of A is in range */
		pb(b, a); /* push to B */
		/* Optional heuristic: if the pushed value is in lower half of chunk, rotate B so smalls go down */
		if (*b && (*b)->value < (minv + maxv) / 2)
			rb(b);
	}
}

/* Main chunk sort function */
void sort_chunk(t_stack **a, t_stack **b)
{
	int len;

	len = stack_size(*a);

	/* Create sorted array */
	int *arr = stack_to_array(*a, len);
	if (!arr)
		return;
	qsort(arr, len, sizeof(int), int_cmp);

	/* choose chunks count heuristically */
	int chunks = 5;
	if (len <= 100)
		chunks = 5;
	else if (len <= 250)
		chunks = 7;
	else
		chunks = 11; /* for 500+ */

	int chunk_size = (len + chunks - 1) / chunks;
	for (int c = 0; c < chunks; ++c)
	{
		int start = c * chunk_size;
		if (start >= len)
			break;
		int end = start + chunk_size - 1;
		if (end >= len)
			end = len - 1;
		int minv = arr[start];
		int maxv = arr[end];
		push_chunk_range(a, b, minv, maxv);
	}
	free(arr);

	/* Now move all from B back to A: bring max in B to top and pa */
	while (*b)
	{
		int max_idx = find_max_index(*b);
		int lenb = stack_size(*b);
		if (max_idx <= lenb / 2)
		{
			while (max_idx-- > 0)
				rb(b);
		}
		else
		{
			int moves = lenb - max_idx;
			while (moves-- > 0)
				rrb(b);
		}
		pa(a, b);
	}

	/* final alignment: ensure smallest is at top */
	/* rotate A until smallest is on top (optional, depending on tests you might want this) */
	/* find index of min and rotate (you can add helper if needed) */
}
