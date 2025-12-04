/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:37:21 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/04 14:27:08 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*last_node;

	if (!stack)
		return (NULL);
	last_node = stack;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	stack_size(t_stack *stack)
{
	t_stack	*curr;
	int		i;

	if (!stack)
		return (0);
	curr = stack;
	i = 0;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_max_value(t_stack *stack)
{
	long	max;
	t_stack	*max_value;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_value = stack;
		}
		stack = stack->next;
	}
	return (max_value);
}

t_stack	*find_min_value(t_stack *stack)
{
	long	min;
	t_stack	*min_value;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_value = stack;
		}
		stack = stack->next;
	}
	return (min_value);
}
