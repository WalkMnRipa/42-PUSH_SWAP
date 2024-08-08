/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:24:22 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/07 14:19:45 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_join(int fd, char *stash, int *nb_carac, int *index)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_result;
	char	*new_stash;

	read_result = read(fd, buffer, BUFFER_SIZE);
	if ((read_result == 0 && !stash) || read_result < 0)
		return (free(stash), NULL);
	buffer[read_result] = '\0';
	new_stash = ft_strjoin(stash, buffer);
	if (!new_stash)
		return (free(stash), NULL);
	*nb_carac = read_result;
	*index = ft_strchr_gnl(new_stash, '\n');
	free(stash);
	return (new_stash);
}

char	*init_stash(char *stash)
{
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

char	*reset_if_empty(char *stash, int nb_carac)
{
	if (!stash)
		return (NULL);
	if (nb_carac == 0 && stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

char	*ft_extract_line(char *stash, int index)
{
	char	*line;

	if (!stash)
		return (NULL);
	if (index == -1)
		index = (int)ft_strlen(stash);
	line = malloc(index + 1);
	if (!line)
		return (NULL);
	line = ft_strncpy(line, stash, index);
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			index;
	int			nb_carac;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	nb_carac = 1;
	index = -1;
	stash = init_stash(stash);
	if (!stash)
		return (NULL);
	while (nb_carac > 0 && index == -1)
	{
		stash = ft_read_and_join(fd, stash, &nb_carac, &index);
		if (!stash)
			return (NULL);
	}
	stash = reset_if_empty(stash, nb_carac);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash, index);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	return (stash = ft_cleanstash(stash, index), line);
}
