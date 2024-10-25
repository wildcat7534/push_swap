/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:25:07 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:30:35 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_index(int *nb, int value)
{
	int	i;

	i = 0;
	while (nb[i] != value)
		i++;
	return (i);
}
int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->nb[0];
	while (i < stack->size)
	{
		if (stack->nb[i] < min)
			min = stack->nb[i];
		i++;
	}
	return (min);
}
int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->nb[0];
	while (i < stack->size)
	{
		if (stack->nb[i] > max)
			max = stack->nb[i];
		i++;
	}
	return (max);
}
