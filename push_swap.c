/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:29:26 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/29 16:55:16 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

/* int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) == 5)
			sort_five(&a, &b);
		else
			sort_chunk(&a, &b);
	}
	free_stack(&a);
	return (0);
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args_to_free; // New pointer to hold the address of the array to free
	int		start_index;

	a = NULL;
	b = NULL;
	args_to_free = NULL;
	start_index = 1; // Default start index for arguments (skips program name)

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		args_to_free = ft_split(argv[1], ' ');
		if (!args_to_free) // handle malloc fail in ft_split
			return (1);
		argv = args_to_free; // Use the newly split array
		start_index = 0; // Start at index 0 because ft_split array has no program name
	}
	
	init_stack_a(&a, argv + start_index);

	if (!a) // Error during stack init (e.g., duplicate, bad syntax)
	{
		if (args_to_free)
			return (1);
	}
	
	if (!stack_sorted(a))
	{
		// Your existing sorting logic...
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) == 5)
			sort_five(&a, &b);
		else
			sort_chunk(&a, &b);
	}

	free_stack(&a);
	if (args_to_free)
		free(args_to_free); // FREE THE ARRAY POINTER ITSELF!

	return (0);
}

