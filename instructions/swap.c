/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:50:12 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 22:58:15 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack **stack)
{
	int	tmp;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[0];
	(*stack)->nb[0] = (*stack)->nb[1];
	(*stack)->nb[1] = tmp;
	(*stack)->size_instructions++;
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	int	tmp;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[0];
	(*stack)->nb[0] = (*stack)->nb[1];
	(*stack)->nb[1] = tmp;
	(*stack)->size_instructions++;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	(*stack_a)->size_instructions++;
	ft_printf("ss\n");
}