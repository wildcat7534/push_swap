/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:50:12 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 19:39:58 by cmassol          ###   ########.fr       */
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
}

void	sb(t_stack **stack)
{
	int	tmp;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->nb[0];
	(*stack)->nb[0] = (*stack)->nb[1];
	(*stack)->nb[1] = tmp;
}

void	ss(t_stack **stack)
{
	sa(stack);
	sb(stack);
}