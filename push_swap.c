/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:29:26 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/11 10:59:12 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_algorithm(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a == 2)
		sa(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a <= 5)
		sort_five(a, b);
	else
		sort_chunk(a, b, size_a);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int make_split(char ***args, char *argv, int *args_splited)
{
	*args = ft_split(argv, ' ');
	*args_splited = 1;
	if (!*args || !*args[0])
	{
		free_args(*args);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		args_splited;

	a = NULL;
	b = NULL;
	args = NULL;
	args_splited = 0;
	if (argc == 1 || (argc == 2))
		return (1);
	if (argc > 2)
		args = argv + 1;
	else if (!make_split(&args, argv[1], &args_splited))
		return (0);
	init_stack_a(&a, args);
	if (!stack_sorted(a))
		choose_algorithm(&a, &b);
	if (args_splited)
		free_args(args);
	free_stack(&a);
	return (0);
}
