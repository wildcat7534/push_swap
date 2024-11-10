/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:49:32 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/01 11:24:10 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
/*
#include <stdio.h>
#include <string.h>

 int	main(void)
{
	char	*str1;
	char	*str2;
	char	*test;
	char	*test2;
	int		n;

	str1 = "Hello";
	str2 = "Hello";
	test = "\200";
	test2 = "\0";
	n = 6;
	printf("test: %s\n", test);
	printf("test2: %s\n", test2);
	printf("n: %d\n", n);
	printf("strncmp: %d\n", strncmp(test, test2, n));
	printf("ft_strncmp: %d\n", ft_strncmp(test, test2, n));
	return (0);
}
*/
