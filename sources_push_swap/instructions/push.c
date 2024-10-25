/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:50:52 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:38:55 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// push the top element of stack b to stack a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if ((*stack_b)->size == 0)
		return ;
	i = (*stack_a)->size;
	while (i > 0)
	{
		(*stack_a)->nb[i] = (*stack_a)->nb[i - 1];
		i--;
	}
	(*stack_a)->nb[0] = (*stack_b)->nb[0];
	i = 0;
	while (i < (*stack_b)->size - 1)
	{
		(*stack_b)->nb[i] = (*stack_b)->nb[i + 1];
		i++;
	}
	(*stack_a)->size++;
	(*stack_b)->size--;
}
// push the top element of stack a to stack b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if ((*stack_a)->size == 0)
		return ;
	i = (*stack_b)->size;
	while (i > 0)
	{
		(*stack_b)->nb[i] = (*stack_b)->nb[i - 1];
		i--;
	}
	(*stack_b)->nb[0] = (*stack_a)->nb[0];
	i = 0;
	while (i < (*stack_a)->size - 1)
	{
		(*stack_a)->nb[i] = (*stack_a)->nb[i + 1];
		i++;
	}
	(*stack_b)->size++;
	(*stack_a)->size--;
}