/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:45:59 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 18:38:14 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbrlen(long n, int *totalchar)
{
	char	c;

	if (n == -2147483648 || n == (int)-2147483648)
	{
		write(1, "-2147483648", 11);
		*totalchar += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putcharlen('-', totalchar);
		n = n * -1;
		ft_putnbrlen(n, totalchar);
	}
	else if (n > 9)
	{
		ft_putnbrlen(n / 10, totalchar);
		ft_putnbrlen(n % 10, totalchar);
	}
	else if (n < 10)
	{
		c = (char)(n + '0');
		write(1, &c, 1);
		(*totalchar)++;
	}
}
