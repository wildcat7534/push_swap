/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:54:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 19:07:45 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putcharlen(char c, int *totalchar)
{
	if (c == '\0')
		write(1, "\0", 1);
	else
		write(1, &c, 1);
	(*totalchar)++;
}
