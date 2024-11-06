/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:38:32 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:03:51 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_node **stack_out, t_node **stack_in)
{
	t_node	*change;

	change = *stack_out;
	*stack_out = change->next;
	change->next = *stack_in;
	*stack_in = change;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
