/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:44:39 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 20:51:38 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_node	*init_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nb = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*current;

	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

int	parse_arguments(int ac, char **av, int *numbers)
{
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return ((free(numbers)), -1);
		j = 0;
		while (split[j])
		{
			if (!ft_isstrnum(split[j]) || ft_atol(split[j]) > INT_MAX
				|| ft_atol(split[j]) < INT_MIN)
				return (free(numbers), ft_free_split(split), ft_error(), -1);
			numbers[count++] = ft_atoi(split[j++]);
		}
		ft_free_split(split);
		i++;
	}
	return (count);
}

int	prepare_numbers(int ac, char **av, int **numbers, int *size)
{
	*numbers = malloc(sizeof(int) * (ac - 1) * ft_nb_words(av[1], ' '));
	if (!*numbers)
		return (1);
	*size = parse_arguments(ac, av, *numbers);
	if (has_duplicates(*numbers,*size))
	{
		free(*numbers);
		return (1);
	}
	return (0);
}

int	make_node(t_node **stack, int ac, char **av, int *size)
{
	t_node	*new_node;
	int		*numbers;
	int		i;

	numbers = NULL;
	if (prepare_numbers(ac, av, &numbers, size))
		return (1);
	*stack = NULL;
	i = 0;
	while (i < *size)
	{
		new_node = init_node(numbers[i++]);
		if (!new_node)
		{
			free(numbers);
			return (1);
		}
		add_node_back(stack, new_node);
	}
	free(numbers);
	return (0);
}
