/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:50:52 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 18:07:24 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->size == 0)
		return ;
	i = stack->size;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[0] = stack->nb[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->nb[i] = stack->nb[i + 1];
		i++;
	}
	stack->size++;
	stack->size--;
}

void	pb(t_stack *stack)
{
	int i;

	if (stack->size == 0)
		return ;
	i = stack->size;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[0] = stack->nb[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->nb[i] = stack->nb[i + 1];
		i++;
	}
	stack->size++;
	stack->size--;
}