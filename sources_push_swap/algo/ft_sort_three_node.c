/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:03:26 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three_node(t_node **stack_a)
{
	t_node	*current_node_max;
	int		max;

	current_node_max = find_max_node(stack_a);
	max = current_node_max->nb;
	if ((*stack_a)->nb == max)
	{
		ra(stack_a);
		if (!is_sorted_node(stack_a))
			sa(stack_a);
	}
	else if ((*stack_a)->next->nb == max)
	{
		rra(stack_a);
		if (!is_sorted_node(stack_a))
			sa(stack_a);
	}
	else if (!is_sorted_node(stack_a))
		sa(stack_a);
}
