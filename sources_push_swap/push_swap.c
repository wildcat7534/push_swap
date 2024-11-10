/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 20:48:21 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (make_node(&a, ac, av, &size))
		return (free_nodes(a), (write(2, "Error\n", 6)), 1);
	if (is_sorted_node(&a))
		return (free_nodes(a), 0);
	ft_sort(&a, &b);
	free_nodes(a);
	free_nodes(b);
	return (0);
}
