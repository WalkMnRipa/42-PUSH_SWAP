/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:24:19 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/24 21:00:57 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_cleanstash(char *stash, int index)
{
	char	*new_stash;
	int		i;
	int		j;

	if (index == -1 || stash[index] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (((int)ft_strlen(stash)) - index) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i = index;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
