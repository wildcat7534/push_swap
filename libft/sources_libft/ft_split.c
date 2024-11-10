/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:02 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/27 16:14:11 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free_split(char **s, size_t i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return ((void *)0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab_str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	tab_str = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab_str)
		return (NULL);
	while (++i < ft_nb_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		tab_str[i] = ft_substr(s, j, ft_word_len(&s[j], c));
		if (!tab_str[i])
			return (ft_free_split(tab_str, i));
		while (s[j] && s[j] != c)
			j++;
	}
	tab_str[i] = NULL;
	return (tab_str);
}
