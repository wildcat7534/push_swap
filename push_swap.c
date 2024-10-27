/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/27 16:22:41 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_arguments(int ac, char **av, int **numbers)
{
	int		*result;
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = 1;
	// Allocation mémoire maximale (ac - 1)
	//*10 pour couvrir les cas de chaînes multiples
	result = malloc(sizeof(int) * (ac - 1) * ft_nb_words(av[1], ' '));
	// Approximatif mais évite des reallocations répétées
	if (!result)
		return (-1);
	while (i < ac)
	{
		// Découper l'argument actuel si nécessaire
		split = ft_split(av[i], ' ');
		if (!split)
		{
			free(result);
			return (-1);
		}
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]))
			{
				free(result);
				ft_free_split(split);
				return (-1); // Valeur non numérique détectée
			}
			result[count++] = ft_atoi(split[j]);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	// Vérification des doublons après parsing complet
	if (has_duplicates(result, count))
	{
		return (free(result), - 1);
	}
	// Assigner les nombres trouvés à numbers et retourner la taille
	*numbers = result;
	return (count);
}
int	init_stack(t_stack **stack_a, int ac, char **av, t_stack **stack_b)
{
	int	*numbers;
	int	total_numbers;

	total_numbers = parse_arguments(ac, av, &numbers);
	// Obtenir tous les nombres
	if (total_numbers == -1)
		return (1); // Erreur dans les arguments
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		return (1);
	(*stack_a)->nb = numbers;
	(*stack_a)->size = total_numbers;
	(*stack_a)->size_instructions = 0;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		return (1);
	(*stack_b)->nb = malloc(sizeof(int) * total_numbers);
	if (!(*stack_b)->nb)
		return (1);
	(*stack_b)->size = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_errors(ac, av))
	{
		// ft_printf("Error basique\n");
		// write in error stdout
		write(2, "Error\n", 6);
		return (1);
	}
	if (init_stack(&stack_a, ac, av, &stack_b))
	{
		// ft_printf("Error init stack\n");
		write(2, "Error\n", 6);
		return (1);
	}
	// ft_printf("stack_a->size = %d\n", stack_a->size);
	// print_stack(stack_a, stack_b);
	if (is_sorted(&stack_a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	print_stack(stack_a, stack_b);
	ft_sort(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	print_nb_instructions(&stack_a);
	//taille de la stack 
	ft_printf("stack_a->size = %d\n", stack_a->size);
	free(stack_a->nb);
	free(stack_a);
	free(stack_b->nb);
	free(stack_b);
	return (0);
}
