/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:52:43 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 22:59:29 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **stack)
{
	int	tmp;
	int	i;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[(*stack)->size - 1];
	i = (*stack)->size - 1;
	while (i > 0)
	{
		(*stack)->nb[i] = (*stack)->nb[i - 1];
		i--;
	}
	(*stack)->nb[0] = tmp;
	(*stack)->size_instructions++;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	int	tmp;
	int	i;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[(*stack)->size - 1];
	i = (*stack)->size - 1;
	while (i > 0)
	{
		(*stack)->nb[i] = (*stack)->nb[i - 1];
		i--;
	}
	(*stack)->nb[0] = tmp;
	(*stack)->size_instructions++;
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	(*stack_a)->size_instructions++;
	ft_printf("rrr\n");
}
