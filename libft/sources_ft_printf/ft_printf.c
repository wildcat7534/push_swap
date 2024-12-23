/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:17:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 18:09:56 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_printf(const char *format, ...);

char	ft_strfindchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str[i]);
		i++;
	}
	return ('\0');
}

void	ft_selectargs(char argfind, va_list args, int *totalchar)
{
	uintptr_t	nb;

	if (argfind == '\0')
		return ;
	if ('c' == argfind)
		ft_putcharlen((char)va_arg(args, int), totalchar);
	if ('s' == argfind)
		ft_putstrlen(va_arg(args, char *), totalchar);
	if ('p' == argfind)
	{
		nb = (uintptr_t)va_arg(args, void *);
		if (nb == 0)
			ft_putstrlen("(nil)", totalchar);
		else
			return (ft_putstrlen("0x", totalchar), ft_putptrlen(nb, totalchar));
	}
	if ('x' == argfind || 'X' == argfind)
		ft_putnbrhexlen(va_arg(args, int), totalchar, argfind);
	if ('d' == argfind || 'i' == argfind)
		ft_putnbrlen(va_arg(args, int), totalchar);
	if ('u' == argfind)
		ft_putnbrlen((unsigned int)va_arg(args, int), totalchar);
	if ('%' == argfind)
		ft_putcharlen('%', totalchar);
}

void	ft_selectargs2(va_list args, int *totalchar)
{
	ft_putnbrlen(va_arg(args, long), totalchar);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		totalchar;
	char	argfind;

	totalchar = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format < (format + ft_strlen(format)))
	{
		if ((char)*format == '%')
		{
			format++;
			argfind = ft_strfindchr("cspdiuxX%", (char) *format);
			if (argfind != '\0')
				ft_selectargs(argfind, args, &totalchar);
			else if ((char) *format == 'l')
				ft_selectargs2(args, &totalchar);
		}
		else
			ft_putcharlen(*format, &totalchar);
		format++;
	}
	va_end(args);
	return (totalchar);
}
