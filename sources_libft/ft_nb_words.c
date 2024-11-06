/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:13:20 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:07:39 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nb);
}
