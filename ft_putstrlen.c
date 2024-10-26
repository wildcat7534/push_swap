/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:44:16 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/25 17:44:22 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstrlen(char *s, int *totalchar)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		s = "(null)";
		while (s[i])
			ft_putcharlen(s[i++], totalchar);
		return ;
	}
	while (s[i])
		ft_putcharlen(s[i++], totalchar);
}
