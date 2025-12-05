/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:30:15 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/12/05 14:02:30 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "./ft_printf/printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct c_chunk
{
	int	chunk_size;
	int	total;
	int	start;
	int	end;
}	t_chunk;

char	**ft_split(char const *s, char c);

// commands
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// errors
int		syntax(char *str_n);
int		duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

// algorithm
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_chunk(t_stack **a, t_stack **b, int size);

// stack init
void	init_stack_a(t_stack **a, char **argv);

// stack utils
t_stack	*find_last_node(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_sorted(t_stack *stack);
t_stack	*find_max_value(t_stack *stack);
t_stack	*find_min_value(t_stack *stack);
void	free_stack(t_stack **stack);

// sort_chunk_utils
int		*clone_values(t_stack *a, int size);
void	sort_array(int *sorted, int size);
int		choose_chunk_size(int size);
int		index_of(int *sorted, int size, int value);
int		position_of(t_stack *stack, t_stack *node);

#endif