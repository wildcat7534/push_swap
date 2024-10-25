/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:38:24 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 18:08:43 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	ft_printf("Stack A:\n");
	while (i < stack_a->size)
	{
		ft_printf("stack_a : %d\n", stack_a->nb[i]);
		i++;
	}
	i = 0;
	ft_printf("Stack B:\n");
	while (i < stack_b->size)
	{
		ft_printf("stack_b : %d\n", stack_b->nb[i]);
		i++;
	}
}