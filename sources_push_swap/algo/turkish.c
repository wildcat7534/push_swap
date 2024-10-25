/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 19:54:23 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// ft_sort_three algorithm
// 1. if the stack is sorted, return
// 2. if the stack has 2 elements, swap them
// 3. if the stack has 3 elements, sort them
// 4. if the stack has more than 3 elements, find the min, max and median
// 5. if the stack has more than 10 elements, split the stack in half and sort each half
// 6. if the stack has less than 10 elements, sort the stack

// split stack

void	split_stack(t_stack *stack_a, int median)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->nb[i] < median)
		{
			pb(stack_a);
			add_instruction(stack_a, "pb");
		}
		else
		{
			ra(stack_a);
			add_instruction(stack_a, "ra");
		}
	}
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

// merge stack

void	merge_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_b->size)
	{
		pa(stack_a);
		add_instruction(stack_a, "pa");
		i++;
	}
}


// turkish sort algorithm

void	turkish_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	median;

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
		min = find_min(*stack_a);
		max = find_max(*stack_a);
		median = (min + max) / 2;
		if (is_sorted(*stack_a))
			return ;
		if ((*stack_a)->size > 10)
		{
			split_stack(*stack_a, median);
			turkish_sort(stack_a, stack_b);
			turkish_sort(stack_b, stack_a);
			merge_stack(*stack_a, *stack_b);
		}
		else
		{
			ft_sort(*stack_a, *stack_b);
		}
	}
}



