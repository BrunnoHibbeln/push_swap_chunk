/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:19:14 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 12:44:52 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *nptr)
{
	int		is_odd;
	long	num;

	num = 0;
	is_odd = 0;
	while ((*nptr == 32) || ((*nptr > 8) && (*nptr < 14)))
		nptr++;
	if ((*nptr == 43) || (*nptr == 45))
	{
		if (*nptr == 45)
			is_odd++;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	if ((is_odd % 2) != 0)
		return (-(num));
	return (num);
}

static void	append_to_stack(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **args)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		if (syntax(args[i]))
			free_errors(a);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (duplicate(*a, (int)n))
			free_errors(a);
		append_to_stack(a, (int)n);
		i++;
	}
}
