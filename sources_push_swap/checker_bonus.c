/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:13:08 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 19:31:43 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_error_bonus(char *line)
{
	free(line);
	write(2, "Error\n", 6);
	exit(1);
}

void	execute_command(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		ft_error_bonus(line);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (make_node(&a, ac, av, &size))
		return ((write(2, "Error\n", 6)), 1);
	line = get_next_line(0);
	while (line)
	{
		execute_command(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_node(&a) && stack_size(&b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_nodes(a);
	free_nodes(b);
	return (0);
}
