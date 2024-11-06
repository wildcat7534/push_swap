/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:40:06 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:04:26 by cmassol          ###   ########.fr       */
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

void	ra(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
