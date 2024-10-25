/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:22:40 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 20:53:39 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_10(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	// Pousser les éléments de stack_a vers stack_b jusqu'à ce qu'il reste 3 éléments
	while ((*stack_a)->size > 3)
	{
		// Trouve le minimum dans stack_a
		min = find_min(*stack_a);

		// Pousse le minimum sur stack_b
		while ((*stack_a)->nb[0] != min)
		// Tant que le min n'est pas au sommet
		{
			if (get_index((*stack_a)->nb, min) <= (*stack_a)->size / 2)
				ra(stack_a); // Rotation vers le haut
			else
				rra(stack_a); // Rotation vers le bas
		}
		pb(stack_a, stack_b); // Pousse le minimum dans stack_b
	}

	// Trie les 3 éléments restants dans stack_a
	ft_sort_three(stack_a);

	// Récupère tous les éléments de stack_b dans stack_a,
	//qui sont déjà en ordre croissant 
	while ((*stack_b)->size > 0)
	{
		pa(stack_a, stack_b);
	}
}