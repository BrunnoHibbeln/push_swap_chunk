/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:37:12 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/26 14:21:59 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	second_node = (*stack)->next;
	second_node->prev = NULL;
	(*stack)->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = *stack;
	second_node->next = *stack;
	(*stack)->prev = second_node;
	*stack = second_node;
}

void	sa(t_stack	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
