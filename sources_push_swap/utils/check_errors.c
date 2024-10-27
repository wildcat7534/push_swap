/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:10:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/27 16:07:29 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_number(char *str)
{
	int	i;
	
	i = 0;
	// Gérer le signe au début
	if (str[i] == '-' || str[i] == '+')
		i++;
	// Vérifier si les caractères restants sont tous des chiffres
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	// Vérifier qu'il y a au moins un chiffre après le signe
	return (i > (str[0] == '-' || str[0] == '+'));
}
int	has_duplicates(int *array, int size)
{
	int i;
	int j;

	i = 0;
	// Comparer chaque élément avec tous les autres
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				ft_printf("DOUBLON !: %i\n", array[i]); //TODO: to erase
				return (1); // Doublon trouvé
			}
			j++;
		}
		i++;
	}
	return (0); // Pas de doublons
}

int	check_errors(int ac, char **av)
{
	int	i;
	int	*numbers;
	// Conversion des arguments en entiers et vérification des doublons
	numbers = malloc(sizeof(int) * (ac - 1));
	if (!numbers)
		return (1);
	i = 0;
	while (i < ac - 1)
	{
		numbers[i] = ft_atoi(av[i + 1]);
		i++;
	}
	if (has_duplicates(numbers, ac - 1)) // Vérifie s'il y a des doublons
	{
		free(numbers);
		return (1);
	}
	free(numbers);
	return (0);
}

/*
int	check_errors(int ac, char **av)
{
	int	i;
	int	j;
	int	k;
	int	i;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (1);
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
				return (1);
			j++;
		}
		k = i + 1;
		while (k < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[k]))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
*/