/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:38:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 18:05:09 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_putcharlen(char c, int *totalchar);
void	ft_putnbrhexlen(unsigned int n, int *totalchar, char param);
void	ft_putnbrlen(long n, int *totalchar);
void	ft_putptrlen(uintptr_t ptr, int *totalchar);
void	ft_putstrlen(char *str, int *totalchar);

#endif