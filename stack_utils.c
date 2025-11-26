/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:37:21 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/26 14:42:40 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_last_node(t_stack *stack)
{
	t_stack *last_node;

	if (!stack)
		return (NULL);
	last_node = stack;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int stack_size(t_stack *stack)
{
	t_stack *curr;
	int i;

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

bool stack_sorted(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack *find_max_value(t_stack *stack)
{
	long max;
	t_stack *max_value;

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

int find_max_index(t_stack *stack)
{
	int	i;
	int	best;
	int	max;

	i = 0;
	best = 0;
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			best = i;
		}
		i++;
		stack = stack->next;
	}
	return (best);
}

void free_stack(t_stack **stack)
{
	t_stack *curr;
	t_stack *tmp;

	if (!stack || !*stack)
		return;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}
