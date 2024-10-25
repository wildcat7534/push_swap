/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:30 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 12:04:07 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = tmp;
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = tmp;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}