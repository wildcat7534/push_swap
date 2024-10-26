/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:04:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/25 17:05:21 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbrhexlen(unsigned int n, int *totalchar, char param)
{
	char			tab17[17];
	char			*base;
	unsigned int	base_len;
	int				k;

	base = "0123456789abcdef";
	if (param == 'X')
		base = "0123456789ABCDEF";
	base_len = ft_strlen(base);
	if (n == 0)
	{
		ft_putcharlen('0', totalchar);
		return ;
	}
	k = 16;
	tab17[k] = '\0';
	while (n > 0)
	{
		tab17[--k] = base[n % base_len];
		n = n / base_len;
	}
	while (tab17[k])
		ft_putcharlen(tab17[k++], totalchar);
}
