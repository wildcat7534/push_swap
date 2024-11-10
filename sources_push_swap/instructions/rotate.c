/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:40:06 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/07 00:17:41 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*change;
	t_node	*current;

	change = *stack;
	current = *stack;
	*stack = change->next;
	while (current->next != NULL)
		current = current->next;
	current->next = change;
	change->next = NULL;
}

void	ra(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_printf("rr\n");
}
