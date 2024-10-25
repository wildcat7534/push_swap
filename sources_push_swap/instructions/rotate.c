/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:30 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:33:24 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack **stack)
{
	int	tmp;
	int	i;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[0];
	i = 0;
	while (i < (*stack)->size - 1)
	{
		(*stack)->nb[i] = (*stack)->nb[i + 1];
		i++;
	}
	(*stack)->nb[(*stack)->size - 1] = tmp;
}
	

void	rb(t_stack **stack)
{
	int	tmp;
	int	i;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[0];
	i = 0;
	while (i < (*stack)->size - 1)
	{
		(*stack)->nb[i] = (*stack)->nb[i + 1];
		i++;
	}
	(*stack)->nb[(*stack)->size - 1] = tmp;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}