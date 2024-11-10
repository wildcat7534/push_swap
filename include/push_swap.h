/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:08:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 18:35:41 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
}					t_node;

int					get_position_in_stack(t_node **stack, int value);
t_node				*init_node(int value);
void				add_node_back(t_node **stack, t_node *new_node);
void				ft_free_split(char **split);
void				free_nodes(t_node *stack);
void				ft_sort(t_node **a, t_node **b);
void				ft_error(void);
void				index_init(t_node **stack, int len);
void				sort_next(t_node **a, t_node **b);
int					stack_size(t_node **stack);
int					parse_arguments(int ac, char **av, int *numbers);
void				print_stack(t_node **stack);
int					first_half_check(t_node **b, int nb, int half_len);
t_node				*find_max_node(t_node **stack);
t_node				*find_min_node(t_node **stack);
int					make_node(t_node **stack, int ac, char **av, int *size);
void				ft_sort_10_node(t_node **stack_a, t_node **stack_b);
void				ft_sort_three_node(t_node **stack_a);
void				ft_index_sort(t_node **a, t_node **b, int start, int end);
int					is_sorted_node(t_node **stack);
int					get_index_node(t_node **stack, int nb);
void				delete_node(t_node **stack, t_node *node_to_delete);
void				pa(t_node **stack_a, t_node **stack_b, int print);
void				pb(t_node **stack_a, t_node **stack_b, int print);
void				sa(t_node **stack, int print);
void				sb(t_node **stack, int print);
void				ss(t_node **stack_a, t_node **stack_b, int print);
void				ra(t_node **stack, int print);
void				rb(t_node **stack, int print);
void				rr(t_node **stack_a, t_node **stack_b, int print);
void				rra(t_node **stack, int print);
void				rrb(t_node **stack, int print);
void				rrr(t_node **stack_a, t_node **stack_b, int print);
int					has_duplicates(int *array, int size);

#endif