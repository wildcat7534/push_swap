/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:19:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/26 11:32:40 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_nb_instructions(t_stack **stack)
{
	ft_printf("nb_instructions = %d\n", (*stack)->size_instructions);
}
/*
void	add_instruction(t_stack **stack, char *instruction)
{
	int	i;

	i = 0;
	while (i < (*stack)->size_instructions)
	{
		i++;
	}
	(*stack)->instructions[i] = ft_strdup(instruction);
	(*stack)->size_instructions++;
}

void	exec_instruction(t_stack *stack, char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		sa(stack);
	else if (ft_strcmp(instruction, "sb") == 0)
		sb(stack);
	else if (ft_strcmp(instruction, "ss") == 0)
		ss(stack);
	else if (ft_strcmp(instruction, "pa") == 0)
		pa(stack);
	else if (ft_strcmp(instruction, "pb") == 0)
		pb(stack);
	else if (ft_strcmp(instruction, "ra") == 0)
		ra(stack);
	else if (ft_strcmp(instruction, "rb") == 0)
		rb(stack);
	else if (ft_strcmp(instruction, "rr") == 0)
		rr(stack);
	else if (ft_strcmp(instruction, "rra") == 0)
		rra(stack);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rrb(stack);
	else if (ft_strcmp(instruction, "rrr") == 0)
		rrr(stack);
	add_instruction(stack, instruction);
}

void	exec_instructions(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_instructions)
	{
		exec_instruction(stack, stack->instructions[i]);
		i++;
	}
}

void	exec_instructions_no_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_instructions)
	{
		exec_instruction(stack, stack->instructions[i]);
		i++;
	}
}

void	exec_instructions_no_print_no_free(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_instructions)
	{
		exec_instruction(stack, stack->instructions[i]);
		i++;
	}
}

void	free_instructions(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_instructions)
	{
		free(stack->instructions[i]);
		i++;
	}
}

void	free_instructions_no_print(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size_instructions)
	{
		free(stack->instructions[i]);
		i++;
	}
}*/
