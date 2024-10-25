/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 19:46:34 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	min;
	int	max;
	int	median;

	if ((*stack)->size == 2)
	{
		sa(stack);
		add_instruction(*stack, "sa");
	}
	else if ((*stack)->size == 3)
	{
		min = (*stack)->nb[0];
		max = (*stack)->nb[0];
		find_min_max_median(*stack, &min, &max, &median);
		if ((*stack)->nb[0] == max)
		{
			ra(*stack);
			add_instruction(*stack, "ra");
		}
		if ((*stack)->nb[1] == max)
		{
			rra(stack);
			add_instruction(*stack, "rra");
		}
		if ((*stack)->nb[0] > (*stack)->nb[1])
		{
			sa(stack);
			add_instruction(*stack, "sa");
		}
	}
}
