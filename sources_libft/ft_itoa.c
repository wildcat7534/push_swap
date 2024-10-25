/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:37:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/01 11:24:10 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_len(long n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*str;

	nbr = (long)n;
	len = ft_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[len] = '\0';
	while (nbr > 0)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

/*
#include "../include/libft.h"
#include <stdio.h>
#include <stdlib.h>

	int main()
{
	int		n;
	char	*str;

	n = 42;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	n = -42;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	n = 0;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	n = 2147483647;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	n = -2147483648;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
