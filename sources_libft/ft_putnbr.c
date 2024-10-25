/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:43:02 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/25 16:43:09 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-', fd);
		nbr = nbr * -1;
		ft_putnbr(nbr, fd);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, fd);
		ft_putchar(nbr % 10 + '0', fd);
	}
	else if (nbr < 10)
		ft_putchar(nbr + '0', fd);
}
