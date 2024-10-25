/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:01 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:30:35 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	median;

	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->size == 2)
	{
		sa(stack_a);
		add_instruction(*stack_a, "sa");
	}
	else if ((*stack_a)->size == 3)
	{
		ft_sort_three(stack_a);
	}
	else
	{
		min = (*stack_a)->nb[0];
		max = (*stack_a)->nb[0];
		find_min_max_median(*stack_a, &min, &max, &median);
		if ((*stack_a)->size > 10)
		{
			split_stack(*stack_a, median);
			ft_sort(stack_a, stack_b);
			ft_sort(stack_b, stack_a);
		}
		else
		{
			ft_sort_10(stack_a, stack_b);
		}
	}
}
// just sort the stack a for ten or less elements
// algorithm: sort the stack a



int is_sorted(t_stack * *stack)
{
	int i;

	i = 0;
	while (i < (*stack)->size - 1)
	{
		if ((*stack)->nb[i] > (*stack)->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int is_rev_sorted(t_stack * stack)
{
	int i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->nb[i] < stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int is_median(t_stack * stack, int median)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == median)
			return (1);
		i++;
	}
	return (0);
}
int is_rev_median(t_stack * stack, int median)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == median)
			return (1);
		i++;
	}
	return (0);
}
void find_min_max_median(t_stack * stack, int *min, int *max, int *median)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] < *min)
			*min = stack->nb[i];
		if (stack->nb[i] > *max)
			*max = stack->nb[i];
		i++;
	}
	*median = (*min + *max) / 2;
}

int is_max(t_stack * stack, int max)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == max)
			return (1);
		i++;
	}
	return (0);
}
int is_min(t_stack *stack, int min)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == min)
			return (1);
		i++;
	}
	return (0);
}
int is_rev_max(t_stack * stack, int max)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == max)
			return (1);
		i++;
	}
	return (0);
}
int is_rev_min(t_stack * stack, int min)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == min)
			return (1);
		i++;
	}
	return (0);
}
