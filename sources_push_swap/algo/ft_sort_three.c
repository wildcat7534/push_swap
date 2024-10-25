/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 23:27:00 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	min;
	int	max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->nb[0] == max && (*stack_a)->nb[1] == min)
	{
		ra(stack_a);
	}
	else if ((*stack_a)->nb[0] == min && (*stack_a)->nb[1] == max)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->nb[0] == max && (*stack_a)->nb[2] == min)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->nb[0] == min && (*stack_a)->nb[2] == max)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->nb[1] == max && (*stack_a)->nb[2] == min)
	{
		rra(stack_a);
	}
	else if ((*stack_a)->nb[1] == min && (*stack_a)->nb[2] == max)
	{
		sa(stack_a);
	}
}
