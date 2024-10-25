/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:01 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 13:33:07 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort(t_stack *stack)
{
	turkish_sort(stack);
}
int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	is_rev_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	is_median(t_stack *stack, int median)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == median)
			return (1);
		i++;
	}
	return (0);
}
int	is_rev_median(t_stack *stack, int median)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == median)
			return (1);
		i++;
	}
	return (0);
}
int	is_max(t_stack *stack, int max)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == max)
			return (1);
		i++;
	}
	return (0);
}
int	is_min(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == min)
			return (1);
		i++;
	}
	return (0);
}
int	is_rev_max(t_stack *stack, int max)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == max)
			return (1);
		i++;
	}
	return (0);
}
int	is_rev_min(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == min)
			return (1);
		i++;
	}
	return (0);
}
