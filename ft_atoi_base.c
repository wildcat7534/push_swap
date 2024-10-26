/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:12:36 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/01 11:25:23 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nb;
	int		sign;
	int		base_len;

	i = 0;
	nb = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_strchr(base, str[i]))
	{
		nb = nb * base_len + (ft_strchr(base, str[i]) - base);
		i++;
	}
	return (nb * sign);
}
