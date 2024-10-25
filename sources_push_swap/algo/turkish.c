/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 13:33:12 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// turkish sort algorithm

void	turkish_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] > stack->a[j])
			{
				tmp = stack->a[i];
				stack->a[i] = stack->a[j];
				stack->a[j] = tmp;
				add_instruction(stack, "sa");
			}
			j++;
		}
		i++;
	}
}
