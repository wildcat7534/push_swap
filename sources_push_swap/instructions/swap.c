/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:41:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 17:31:55 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_node	**stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **stack, int print)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_printf("ss\n");
}
