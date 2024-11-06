/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:41:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:04:54 by cmassol          ###   ########.fr       */
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

void	sa(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
