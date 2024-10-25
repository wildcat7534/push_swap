/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:52:43 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 12:04:07 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a < 2)
		return ;
	tmp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b < 2)
		return ;
	tmp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}

void	print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size_a)
	{
		ft_printf("%d ", stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < stack->size_b)
	{
		ft_printf("%d ", stack->b[i]);
		i++;
	}
	ft_printf("\n");
}