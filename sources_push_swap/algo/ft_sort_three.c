/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 18:07:24 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->nb[0] > stack->nb[1])
		{
			sa(stack);
			add_instruction(stack, "sa");
		}

	}
	if (stack->size == 3)
	{
		if (stack->nb[0] > stack->nb[1] && stack->nb[1] < stack->nb[2] && stack->nb[0] < stack->nb[2])
		{
			sa(stack);
			add_instruction(stack, "sa");
			rra(stack);
			add_instruction(stack, "rra");
		}
		else if (stack->nb[0] > stack->nb[1] && stack->nb[1] > stack->nb[2])
		{
			sa(stack);
			add_instruction(stack, "sa");
			ra(stack);
			add_instruction(stack, "ra");
		}
		else if (stack->nb[0] > stack->nb[1] && stack->nb[1] < stack->nb[2] && stack->nb[0] > stack->nb[2])
		{
			ra(stack);
			add_instruction(stack, "ra");
		}
		else if (stack->nb[0] < stack->nb[1] && stack->nb[1] > stack->nb[2] && stack->nb[0] > stack->nb[2])
		{
			sa(stack);
			add_instruction(stack, "sa");
		}
		else if (stack->nb[0] < stack->nb[1] && stack->nb[1] > stack->nb[2] && stack->nb[0] < stack->nb[2])
		{
			rra(stack);
			add_instruction(stack, "rra");
		}
	}
}
