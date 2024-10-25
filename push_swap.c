/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 23:31:46 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// init stack for turkish sort algorithm
// 1. create a stack a and stack b
// 2. stack a is filled with the numbers from the arguments
// 3. stack b is empty
// 4. instructions is empty
// 5. size_a is the number of arguments
// 6. size_b is 0
// 7. size_instructions is 0
// 8. a is an array of integers
// 9. b is an array of integers
// 10. instructions is an array of strings
// 11. return 0 if everything is ok, 1 if there is an error

int	init_stack(t_stack **stack_a, int ac, char **av, t_stack **stack_b)
{
	int	i;

	i = 1;
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		return (1);
	(*stack_a)->nb = malloc(sizeof(int) * ac);
	if (!(*stack_a)->nb)
		return (1);
	while (i < ac)
	{
		(*stack_a)->nb[i - 1] = ft_atoi(av[i]);
		i++;
	}
	(*stack_a)->size = ac - 1;
	(*stack_a)->size_instructions = 0;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		return (1);
	(*stack_b)->nb = malloc(sizeof(int) * ac);
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
		return (1);
	if (check_errors(ac, av))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (init_stack(&stack_a, ac, av, &stack_b))
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("stack_a->size = %d\n", stack_a->size);
	print_stack(stack_a, stack_b);
	if (is_sorted(&stack_a))
		return (0);
	turkish_sort(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	print_nb_instructions(&stack_a);
	free(stack_a->nb);
	free(stack_a);
	free(stack_b->nb);
	free(stack_b);
	return (0);
}
