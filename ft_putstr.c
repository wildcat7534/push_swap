/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:32:02 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/25 16:46:44 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		s = "(null)";
		while (s[i])
			ft_putchar(s[i++]);
		return ;
	}
	while (s[i])
		ft_putchar(s[i++]);
}
