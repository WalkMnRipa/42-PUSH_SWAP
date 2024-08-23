/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:16:57 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/23 18:41:32 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

/*********************PARSING**********************/
int			is_valid(char *str);
int			already_exists(t_stack *stack, int nb);
int			add_number_in_stack(t_stack *stack, char *str);
int			parse_single_argument(t_push_swap *ps, char *str);
int			parse_multiple_arguments(t_push_swap *ps, int nb_args, char **av);
int			parse_arguments(t_push_swap *ps, int ac, char **av);

/*********************INIT**********************/
t_stack		*init_stack(int max_size);
t_push_swap	*init_push_swap(int size);

/*********************CLEAN**********************/
void		ft_cleanup_and_print_error(t_push_swap *ps);
void		free_push_swap(t_push_swap *ps);

/*********************UTILS**********************/
int			count_total_numbers(int ac, char **av);
void		ft_free_split(char **split);
int			find_min_value_in_stack(t_stack *a);
int			find_max(t_stack *a);
int			find_minValue_ReturnIndex(t_stack *a);
int			find_index_in_stack(int *tab, int size, int nb);
int			get_max_bites(int max);
int			is_sorted(t_stack *a);
void		bubble_sort(int *arr, int n);
void		ft_copy_stack(int *dest, int *src, int n);

/*******************MOVEMENTS********************/
void		ft_sa(t_push_swap *ps);
void		ft_sb(t_push_swap *ps);
void		ft_ss(t_push_swap *ps);
void		ft_pa(t_push_swap *ps);
void		ft_pb(t_push_swap *ps);
void		ft_ra(t_push_swap *ps);
void		ft_rb(t_push_swap *ps);
void		ft_rr(t_push_swap *ps);
void		ft_rra(t_push_swap *ps);
void		ft_rrb(t_push_swap *ps);
void		ft_rrr(t_push_swap *ps);

/*********************SORT**********************/
void		sort_two(t_push_swap *ps);
void		sort_three(t_push_swap *ps);
void		sort_small_set(t_push_swap *ps);
void		simplify_stack(t_push_swap *ps);
void		radix_sort(t_push_swap *ps);

#endif
