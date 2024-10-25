/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 16:18:12 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	if (stack->size_a == 3)
	{
		if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
			ra(stack);
		if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
			sa(stack);
		if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
			rra(stack);
		if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
			ra(stack);
		if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] < stack->a[2])
			sa(stack);
	}
}
