/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/26 17:22:25 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// ft_sort_three algorithm
// 1. if the stack is sorted, return
// 2. if the stack has 2 elements, swap them
// 3. if the stack has 3 elements, sort them
// 4. if the stack has more than 3 elements, find the min, max and median
// 5. if the stack has more than 10 elements,
// split the stack in half and sort each half
// 6. if the stack has less than 10 elements, sort the stack

// split stack

void	split_stack(t_stack **stack_a, int median, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i < (*stack_a)->size)
	{
		if ((*stack_a)->nb[0] < median)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			ra(stack_a);
		}
	}
}
// merge stack

void	merge_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i < (*stack_b)->size)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

// turkish sort algorithm

void	algo_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if ((*stack_a)->size == 2)
		sa(stack_a);
	else if ((*stack_a)->size == 3)
	{
		ft_sort_three(stack_a);
	}
	else if ((*stack_a)->size < 10)
	{
		ft_sort_10(stack_a, stack_b);
	}
	else
	{
		turkish_sort(stack_b, stack_a);
	}
}
// turkish sort engine

int	find_median(int *array, int size)
{
	int	*copy;
	int	median;

	// Copier et trier l'array pour trouver la médiane
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (0); // Gérer l'erreur si malloc échoue
	for (int i = 0; i < size; i++)
		copy[i] = array[i];
	// Tri de la copie (exemple avec une fonction de tri simple)
	sort_array(copy, size);
	// La médiane est l'élément du milieu
	median = copy[size / 2];
	free(copy);
	return (median);
}

void	sort_array(int *array, int size)
{
	int	tmp;
	int	i;
	int	j;

	// Tri simple par sélection (à optimiser pour les grandes tailles)
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void	push_largest_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	largest_index;

	while ((*stack_b)->size > 0)
	{
		// Trouver l'index du plus grand élément dans stack_b
		largest_index = find_largest_index((*stack_b)->nb, (*stack_b)->size);
		// Amener le plus grand élément en haut de stack_b
		while (largest_index != 0)
		{
			if (largest_index <= (*stack_b)->size / 2)
				rb(stack_b); // Faire rb jusqu'à ce qu'il soit en haut
			else
				rrb(stack_b); // Faire rrb si plus proche de la fin
			largest_index = find_largest_index((*stack_b)->nb,
					(*stack_b)->size);
		}
		// Pousser le plus grand élément vers stack_a
		pa(stack_a, stack_b); // pa
	}
}

int	find_largest_index(int *array, int size)
{
	int	largest;
	int	index;

	largest = array[0];
	index = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] > largest)
		{
			largest = array[i];
			index = i;
		}
	}
	return (index);
}
/*
void	turkish_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pivot;
	int	i;
	int	original_size;

	// 1. Définir la taille initiale de la pile A
	original_size = (*stack_a)->size;
	// 2. Sélectionner un pivot, ici la médiane
	pivot = find_median((*stack_a)->nb, (*stack_a)->size);
	// 3. Diviser stack_a en deux (éléments plus petits que le pivot vont vers B)
	i = 0;
	while (i < original_size)
	{
		if ((*stack_a)->nb[0] < pivot)
			push_b(stack_a, stack_b); // pb : pousse vers stack_b
		else
			rotate_a(stack_a); // ra : rotation de stack_a
		i++;
	}
	// 4. Répéter l'opération sur les sous-ensembles de stack_a si nécessaire
	// Par exemple : Si vous avez plus de 3 éléments restants dans stack_a,
	// vous pouvez appliquer récursivement l'algorithme sur chaque moitié.
	// 5. Trier les éléments restants dans stack_b et les remettre dans stack_a
	push_largest_to_a(stack_a, stack_b);
}*/
// Tri de sous-piles de petite taille (exemple de tri pour 3 éléments)
void	sort_small_stack(t_stack **stack)
{
	if ((*stack)->size == 2 && (*stack)->nb[0] > (*stack)->nb[1])
		sa(stack); // sa : échange les deux premiers éléments si désordonnés
	else if ((*stack)->size == 3)
	{
		// Tri de 3 éléments
		if ((*stack)->nb[0] > (*stack)->nb[1])
			sa(stack);
		if ((*stack)->nb[1] > (*stack)->nb[2])
		{
			ra(stack);
			sa(stack);
			rra(stack);
		}
		if ((*stack)->nb[0] > (*stack)->nb[1])
			sa(stack);
	}
}

// Fonction récursive pour diviser et trier
void	recursive_turkish_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pivot;
	int	original_size;
	int	i;

	// Cas de base : si la taille de la pile est gérable directement
	if ((*stack_a)->size <= 3)
	{
		sort_small_stack(stack_a);
		return ;
	}
	// 1. Sélectionner un pivot (ici, la médiane)
	pivot = find_median((*stack_a)->nb, (*stack_a)->size);
	original_size = (*stack_a)->size;
	i = 0;
	// 2. Diviser la pile A en deux (éléments plus petits vers B)
	while (i < original_size)
	{
		if ((*stack_a)->nb[0] < pivot)
			pb(stack_a, stack_b); // pb
		else
			ra(stack_a); // ra
		i++;
	}
	// 3. Appeler récursivement la fonction sur les deux piles divisées
	recursive_turkish_sort(stack_a, stack_b);
	// Traiter la partie restante de stack_a
	push_largest_to_a(stack_a, stack_b);
	// Récupérer les éléments de stack_b vers stack_a
}

/*void	turkish_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	pos;

	recursive_turkish_sort(stack_a, stack_b); // Appel initial
}*/
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	pos;

	while ((*stack_b)->size > 0)
	{
		max = find_max(*stack_b);
		// Trouve l'élément maximum de stack_b
		pos = get_index((*stack_b)->nb, max); // Récupère l'index de cet élément
		// Optimiser les rotations pour amener le max au sommet de stack_b
		if (pos <= (*stack_b)->size / 2)
		{
			while ((*stack_b)->nb[0] != max)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->nb[0] != max)
				rrb(stack_b);
		}
		pa(stack_a, stack_b); // Pousse l'élément maximum dans stack_a
	}
}

int	get_nth_smallest(int *array, int size, int n)
{
	int	*copy;
	int	smallest;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (0);
	for (int i = 0; i < size; i++)
		copy[i] = array[i];
	sort_array(copy, size);
	smallest = copy[n];
	free(copy);
	return (smallest);
}

void	turkish_sort(t_stack **stack_a, t_stack **stack_b)
{
	int pivot1, pivot2, pivot3;
	int i, size;
	size = (*stack_a)->size;
	// Divisez stack_a en trois chunks avec trois pivots différents
	pivot1 = get_nth_smallest((*stack_a)->nb, size, size / 4);
	// Premier pivot (25%)
	pivot2 = get_nth_smallest((*stack_a)->nb, size, size / 2);
	// Deuxième pivot (50%)
	pivot3 = get_nth_smallest((*stack_a)->nb, size, 3 * size / 4);
	// Troisième pivot (75%)
	// Première passe pour pousser les éléments vers stack_b en fonction des pivots
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->nb[0] <= pivot1)
		{
			pb(stack_a, stack_b);
			// Pousse les éléments les plus petits dans stack_b
			rb(stack_b);
			// Effectuer une rotation pour garder l'ordre dans stack_b
		}
		else if ((*stack_a)->nb[0] <= pivot2)
		{
			pb(stack_a, stack_b); // Pousse les éléments moyens vers stack_b
		}
		else if ((*stack_a)->nb[0] <= pivot3)
		{
			ra(stack_a);
				// Effectue une rotation de stack_a pour garder ces éléments pour l'instant
		}
		else
		{
			ra(stack_a);
			// Garde les éléments les plus grands dans stack_a pour le moment
		}
		i++;
	}
	// Trier les petits segments restants dans stack_a
	ft_sort_three(stack_a);
	// Pousse les éléments de stack_b vers stack_a dans l'ordre croissant
	push_back_to_a(stack_a, stack_b);
}
