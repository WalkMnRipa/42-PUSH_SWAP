/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:24:23 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/13 18:40:01 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr_gnl(char *str, char c);

char	*get_next_line(int fd);
char	*ft_cleanstash(char *stash, int index);
char	*ft_extract_line(char *stash, int index);
char	*ft_read_and_join(int fd, char *stash, int *nb_carac, int *index);
char	*reset_if_empty(char *stash, int nb_carac);
char	*ft_strncpy(char *dest, char *src, int n);

#endif