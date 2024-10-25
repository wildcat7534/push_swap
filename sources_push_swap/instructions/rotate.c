/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:30 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 23:30:35 by cmassol          ###   ########.fr       */
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
	(*stack)->size_instructions++;
	ft_printf("ra\n");
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
	(*stack)->size_instructions++;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	(*stack_a)->size_instructions++;
	ft_printf("rr\n");
}