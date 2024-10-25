/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:08:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 16:10:24 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				median;
	int				index;
	int				*a;
	int				*b;
	int				size_a;
	int				size_b;
	int				size_instructions;
	char			**instructions;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	print_stacks(t_stack *stack);
void	print_instructions(t_stack *stack);
void	add_instruction(t_stack *stack, char *instruction);
void	exec_instruction(t_stack *stack, char *instruction);
int		check_errors(int ac, char **av);
int		init_stack(t_stack *stack, int ac, char **av);
int		is_sorted(t_stack *stack);
int		is_rev_sorted(t_stack *stack);
int		is_median(t_stack *stack, int median);
int		is_rev_median(t_stack *stack, int median);
int		is_max(t_stack *stack, int max);
int		is_min(t_stack *stack, int min);
int		is_rev_max(t_stack *stack, int max);
int		is_rev_min(t_stack *stack, int min);
void	turkish_sort(t_stack *stack_a);
int		ft_sort(t_stack *stack);

#endif