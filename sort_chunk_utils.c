/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:19:00 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/29 17:12:23 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *stack_to_array(t_stack *a, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return NULL;
	while (a && i < len)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

/* Helper: does stack contain any value in [minv,maxv]? */
int stack_contains_in_range(t_stack *stack, int minv, int maxv)
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
int index_of_first_in_range(t_stack *a, int minv, int maxv)
{
	int		size;
	int		top_idx;
	int		bottom_idx;
	t_stack	*curr_top;
	t_stack	*curr_bottom;

	size = stack_size(a);
	if (size == 0)
		return (-1);
        
	top_idx = 0;
	bottom_idx = size - 1;
	curr_top = a;
	curr_bottom = find_last_node(a); // Assuming this is correct
	
    // Loop until the pointers meet or cross, checking both ends
	while (top_idx <= bottom_idx)
	{
		// 1. Check from the top (ra moves)
		if (curr_top && curr_top->value >= minv && curr_top->value <= maxv)
			return (top_idx);
		
		// 2. Check from the bottom (rra moves)
		// We use top_idx != bottom_idx to prevent checking the same middle element twice when size is odd
		if (curr_bottom && curr_top != curr_bottom && curr_bottom->value >= minv && curr_bottom->value <= maxv)
			return (bottom_idx);

		// Advance pointers
		if (curr_top)
			curr_top = curr_top->next;
		if (curr_bottom)
			curr_bottom = curr_bottom->prev;
		
		top_idx++;
		bottom_idx--;
	}
	return (-1);
}

/* Helper: rotate A to bring element at index idx to top with minimal moves */
void rotate_a_to_index(t_stack **a, int idx)
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

/* Helper: finds the index of the element in range that is CLOSEST to the top of A */
int	get_best_elem_index(t_stack *a, int minv, int maxv)
{
	int		size;
	int		top_idx;
	int		bottom_idx;
	t_stack	*curr;
	t_stack	*last;

	size = stack_size(a);
	top_idx = 0;
	bottom_idx = size - 1;
	curr = a;
	last = find_last_node(a);

	while (top_idx <= size / 2 || bottom_idx >= size / 2)
	{
		// 1. Check from the top (ra moves)
		if (curr && curr->value >= minv && curr->value <= maxv)
			return (top_idx);
		
		// 2. Check from the bottom (rra moves)
		if (last && last->value >= minv && last->value <= maxv)
			return (bottom_idx);

		if (curr)
			curr = curr->next;
		if (last)
			last = last->prev;
		
		top_idx++;
		bottom_idx--;
	}
	return (-1);
}
