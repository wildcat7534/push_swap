/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:35:29 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/25 16:57:33 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putptrlen(uintptr_t ptr, int *totalchar)
{
	unsigned long	nbr;
	char			c;

	nbr = (unsigned long)ptr;
	if (nbr > 15)
	{
		ft_putptrlen((nbr / 16), totalchar);
		ft_putptrlen((nbr % 16), totalchar);
	}
	else if (nbr < 16)
	{
		if (nbr < 10)
			c = (char)(nbr + '0');
		else
			c = (char)(nbr + 'a' - 10);
		write(1, &c, 1);
		(*totalchar)++;
	}
}
