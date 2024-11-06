/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:25:07 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 03:51:18 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort(t_node **a, t_node **b)
{
	int	start;
	int	end;

	start = 0;
	if (stack_size(a) <= 100)
		end = stack_size(a) / 8;
	else if (stack_size(a) <= 300)
		end = stack_size(a) / 10;
	else
		end = stack_size(a) / 15;
	if (stack_size(a) <= 3)
		ft_sort_three_node(a);
	else if (stack_size(a) <= 10)
		ft_sort_10_node(a, b);
	else
		ft_index_sort(a, b, start, end);
}

int	stack_size(t_node **stack)
{
	int		size;
	t_node	*current;

	current = *stack;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	index_init(t_node **stack, int len)
{
	int		i;
	int		min;
	t_node	*current;
	t_node	*checkpoint;

	i = 1;
	while (len > 0)
	{
		min = INT_MAX;
		current = *stack;
		while (current)
		{
			if (current->nb < min && current->index == -1)
			{
				min = current->nb;
				checkpoint = current;
			}
			current = current->next;
		}
		checkpoint->index = i;
		i++;
		len--;
	}
}

int	is_sorted_node(t_node **stack)
{
	t_node	*current;

	if (!stack || !*stack)
		return (-1);
	current = *stack;
	while (current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}
