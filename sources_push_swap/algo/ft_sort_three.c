/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:52:25 by cmassol          ###   ########.fr       */
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
		sa(stack_a);
		add_instruction(*stack_a, "sa");
	}
	else if ((*stack_a)->nb[0] == min && (*stack_a)->nb[1] == max)
	{
		ra(stack_a);
		add_instruction(*stack_a, "ra");
	}
	else if ((*stack_a)->nb[0] == max && (*stack_a)->nb[2] == min)
	{
		rra(stack_a);
		add_instruction(*stack_a, "rra");
	}
	else if ((*stack_a)->nb[0] == min && (*stack_a)->nb[2] == max)
	{
		sa(stack_a);
		add_instruction(*stack_a, "sa");
		ra(stack_a);
		add_instruction(*stack_a, "ra");
	}
	else if ((*stack_a)->nb[1] == max && (*stack_a)->nb[2] == min)
	{
		ra(stack_a);
		add_instruction(*stack_a, "ra");
		sa(stack_a);
		add_instruction(*stack_a, "sa");
	}
}
