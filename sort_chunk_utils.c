/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:50:57 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 13:52:16 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*clone_values(t_stack *a, int size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (a)
	{
		sorted[i++] = a->value;
		a = a->next;
	}
	return (sorted);
}

void	sort_array(int *sorted, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	choose_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 11);
}

int	index_of(int *sorted, int size, int value)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (value == sorted[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int	position_of(t_stack *stack, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack && stack != node)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}
