/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:05:24 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 13:58:47 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	value_is_in_chunk(int start, int end, int *sorted, int value)
{
	return (value >= sorted[start] && value <= sorted[end]);
}

static void	update_chunk(t_chunk *chunk, int *pushed)
{
	chunk->start += chunk->chunk_size;
	chunk->end += chunk->chunk_size;
	*pushed = 0;
	if (chunk->end >= chunk->size)
		chunk->end = chunk->size - 1;
}

static void	send_a_to_b(t_stack **a, t_stack **b,
						int *sorted, t_chunk *chunk)
{
	int	idx;
	int	value;
	int	pushed;

	pushed = 0;
	while (*a)
	{
		value = (*a)->value;
		if (value_is_in_chunk(chunk->start, chunk->end, sorted, value))
		{
			pb(b, a);
			pushed++;
			idx = index_of(sorted, chunk->size, value);
			if (idx && idx < chunk->start + (chunk->chunk_size / 2))
				rb(b);
		}
		else
			ra(a);
		if (pushed == (chunk->end - chunk->start + 1))
			update_chunk(chunk, &pushed);
	}
}

static void	send_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*max;
	int		pos;

	while (*b)
	{
		max = find_max_value(*b);
		pos = position_of(*b, max);
		if (pos <= stack_size(*b) / 2)
		{
			while (*b != max)
				rb(b);
		}
		else
		{
			while (*b != max)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_chunk(t_stack **a, t_stack **b, int size)
{
	t_chunk		chunk;
	int			*sorted;

	sorted = clone_values(*a, size);
	sort_array(sorted, size);
	chunk.chunk_size = choose_chunk_size(size);
	chunk.size = size;
	chunk.start = 0;
	chunk.end = chunk.chunk_size - 1;
	send_a_to_b(a, b, sorted, &chunk);
	send_b_to_a(a, b);
	free(sorted);
}
