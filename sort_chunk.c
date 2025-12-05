/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:05:24 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 11:43:33 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	value_is_in_chunk(int start, int end, int *sorted, int value)
{
	return (value >= sorted[start] && value <= sorted[end]);
}

static void	update_chunk(t_info *c_info, int *pushed)
{
	c_info->start += c_info->chunk_size;
	c_info->end += c_info->chunk_size;
	*pushed = 0;
	if (c_info->end >= c_info->size)
		c_info->end = c_info->size - 1;
}

static void	send_a_to_b(t_stack **a, t_stack **b,
						int *sorted, t_info *c_info)
{
	int	idx;
	int	value;
	int	pushed;

	pushed = 0;
	while (*a)
	{
		value = (*a)->value;
		if (value_is_in_chunk(c_info->start, c_info->end, sorted, value))
		{
			pb(b, a);
			pushed++;
			idx = index_of(sorted, c_info->size, value);
			if (idx && idx < c_info->start + (c_info->chunk_size / 2))
				rb(b);
		}
		else
			ra(a);
		if (pushed == (c_info->end - c_info->start + 1))
			update_chunk(c_info, &pushed);
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
	t_info		c_info;
	int			*sorted;

	sorted = clone_values_sorted(*a, size);
	sort_array(sorted, size);
	c_info.chunk_size = choose_chunk_size(size);
	c_info.size = size;
	c_info.start = 0;
	c_info.end = c_info.chunk_size - 1;
	send_a_to_b(a, b, sorted, &c_info);
	send_b_to_a(a, b);
	free(sorted);
}
