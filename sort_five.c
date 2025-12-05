/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:41:28 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 13:18:19 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->value == find_min_value(*a)->value)
			pb(b, a);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
