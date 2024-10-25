/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 16:16:38 by cmassol          ###   ########.fr       */
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

int	init_stack(t_stack *stack, int ac, char **av)
{
	int	i;

	stack->size_a = ac - 1;
	stack->size_b = 0;
	stack->size_instructions = 0;
	stack->a = malloc(sizeof(int) * stack->size_a);
	stack->b = malloc(sizeof(int) * stack->size_a);
	stack->instructions = malloc(sizeof(char *) * stack->size_a);
	if (!stack->a || !stack->b || !stack->instructions)
		return (1);
	i = 1;
	while (i <= stack->size_a)
	{
		stack->a[i] = ft_atoi(av[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct s_stack stack;

	stack->a = NULL;
	stack->b = NULL;
	if (ac < 2)
		return (1);
	if (check_errors(ac, av))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (init_stack(&stack, ac, av))
	{
		ft_printf("Error\n");
		return (1);
	}
	print_stacks(&stack);
	ft_sort(&stack);
	// exec_instructions(&a);
	print_instructions(&stack);
	return (0);
}