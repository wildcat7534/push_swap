/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 16:18:11 by cmassol          ###   ########.fr       */
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

// find the min, max and median of the stack



// turkish sort algorithm

void	turkish_sort(t_stack *stack_a)
{
	int	min;
	int	max;
	int	median;

	if (is_sorted(stack_a))
		return ;
	if (stack_a <= 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	min = stack_a->a[0];
	max = stack_a->a[0];
	median = stack_a->a[0];
	find_min_max_median(stack_a, &min, &max, &median);
// 	if stack is above 10, we split the stack in half and sort each half
// 	we then merge the two stacks
	if (stack_a->size_a > 10)
	{
		split_stack(stack_a, min, max, median);
		turkish_sort(stack_a);
		turkish_sort(stack_b);
		merge_stack(stack_a, stack_b);
	}
// 	if stack is below 10, we sort the stack
	else
	{
		sort_stack(stack_a, min, max, median);
	}
}

// sort the stack

int	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	turkish_sort(stack_a, stack_b);
	return (0);
}


