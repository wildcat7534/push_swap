/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:08:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/26 13:03:58 by cmassol          ###   ########.fr       */
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
	int				*nb;
	int				size;
	int				size_instructions;
}					t_stack;

void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **stack, t_stack **stack_b);
void				pa(t_stack **stack, t_stack **stack_b);
void				pb(t_stack **stack, t_stack **stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack, t_stack **stack_b);
void				print_stack(t_stack *stack, t_stack *stack_b);
void				print_nb_instructions(t_stack **stack);
void				add_instruction(t_stack **stack, char *instruction);
void				exec_instruction(t_stack *stack, char *instruction);
int					check_errors(int ac, char **av);
int					init_stack(t_stack **stack, int ac, char **av, t_stack **stack_b);
int					is_number(char *str);
int					has_duplicates(int *array, int size);
int					parse_args(int ac, char **av, int **array);
int					is_sorted(t_stack **stack);
int					is_rev_sorted(t_stack *stack);
int					is_median(t_stack *stack, int median);
int					is_rev_median(t_stack *stack, int median);
int					is_max(t_stack *stack, int max);
int					is_min(t_stack *stack, int min);
int					is_rev_max(t_stack *stack, int max);
int					is_rev_min(t_stack *stack, int min);
void				algo_sort(t_stack **stack_a, t_stack **stack_b);
void				turkish_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_three(t_stack **stack_a);
void				ft_sort_10(t_stack **stack_a, t_stack **stack_b);
void				ft_free_split(char **split);
void				find_min_max_median(t_stack *stack, int *min, int *max, int *median);
void				split_stack(t_stack **stack_a, int median, t_stack **stack_b);
int					find_median(int *array, int size);
void				merge_stack(t_stack **stack_a, t_stack **stack_b);
int					get_index(int *nb, int value);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_largest_index(int *array, int size);
void				push_largest_to_a(t_stack **stack_a, t_stack **stack_b);
void				sort_array(int *array, int size);
void				recursive_turkish_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_small_stack(t_stack **stack);

#endif