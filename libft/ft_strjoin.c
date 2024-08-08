/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:28:04 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/13 18:38:16 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	str_join = (char *)malloc((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str_join[i++] = s2[j++];
	}
	str_join[i] = '\0';
	return (str_join);
}
