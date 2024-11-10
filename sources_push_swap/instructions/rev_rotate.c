/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:42:29 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/07 00:17:15 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*first;

	first = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	current->next->next = first;
	current->next = NULL;
}

void	rra(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	rev_rotate(stack);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	rev_rotate(stack);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_printf("rrr\n");
}
