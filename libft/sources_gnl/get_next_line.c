/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:03 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 19:26:49 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_line_found(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str == NULL)
		return (free(str), str = NULL, NULL);
	if (str[0] == 0)
	{
		return (free(str), str = NULL, NULL);
	}
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[++i] = '\0';
	return (line);
}

char	*line_right(char *str)
{
	int		i;
	int		j;
	char	*lineright;

	i = 0;
	if (str[0] == 0)
	{
		return (free(str), str = NULL, NULL);
	}
	while (str[i] != '\n' && str[i])
		i++;
	lineright = malloc(sizeof(*str) * (ft_strlen(str) - i + 1));
	if (!lineright)
		return (NULL);
	j = 0;
	while (str[i])
		lineright[j++] = str[++i];
	lineright[j] = '\0';
	free(str);
	str = NULL;
	return (lineright);
}

char	*make_stash(int fd, char *str_stash)
{
	char	*buffer;
	int		o_read;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	o_read = 1;
	while (!ft_strrchr(str_stash, '\n') && o_read != 0)
	{
		o_read = read(fd, buffer, BUFFER_SIZE);
		if (o_read == -1)
			return (free(buffer), buffer = NULL, NULL);
		if (o_read == 0 && str_stash[0] == 0)
		{
			free(str_stash);
			str_stash = NULL;
			break ;
		}
		buffer[o_read] = '\0';
		str_stash = ft_strjoin(str_stash, buffer);
	}
	free(buffer);
	return (str_stash);
}

char	*get_next_line(int fd)
{
	static char	*str_stash;
	char		*line;
	char		*temp;

	if (!str_stash)
		str_stash = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str_stash), str_stash = NULL, NULL);
	str_stash = make_stash(fd, str_stash);
	line = get_line_found(str_stash);
	if (!line)
		return (str_stash = NULL, free(str_stash), NULL);
	temp = line_right(str_stash);
	str_stash = ft_strdup(temp);
	free(temp);
	temp = NULL;
	return (line);
}
