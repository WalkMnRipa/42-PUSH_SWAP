/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:16:57 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/09 17:13:03 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_printf_art(void);

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		max_size;
}			t_stack;

typedef struct push_swap
{
	t_stack	*a;
	t_stack	*b;
}			t_push_swap;

int			is_valid(char *str);
int			already_exists(t_stack *stack, int nb);
void		split_and_add_in_stack(t_push_swap *a, char *str);
void		add_arguments_in_stack(t_push_swap *ps, int ac, char **av);
void		ft_cleanup_and_print_error(t_push_swap *ps, char *error);
void		free_push_swap(t_push_swap *ps);
t_stack		*init_stack(int max_size);
t_push_swap	*init_push_swap(int size);

#endif
