/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:52:43 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 18:07:24 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->nb[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[0] = tmp;
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->nb[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[0] = tmp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}

void	print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->nb[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->nb[i]);
		i++;
	}
	ft_printf("\n");
}