/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:03:46 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/09 17:10:35 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_all_checkers(t_push_swap *ps, char c)
{
    
}

int	already_exists(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}


void	split_and_add_in_stack(t_push_swap *ps, char *str)
{
	int		i;
	char	**split;
	long	nb;

	split = ft_split(str, ' ');
	if (!split)
		ft_cleanup_and_print_error(ps, "Error: Memory allocation failed");
	i = 0;
	while (split[i])
	{
		if (!is_valid(split[i]))
			ft_cleanup_and_print_error(ps, "Error: Invalid number");
		nb = ft_atol(split[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_cleanup_and_print_error(ps, "Error: Number out of range");
		if (already_exists(ps->a, (int)nb))
			ft_cleanup_and_print_error(ps, "Error: Duplicate number");
		if (ps->a->size == ps->a->max_size)
			ft_cleanup_and_print_error(ps, "Error: Too many arguments");
		ps->a->stack[ps->a->size] = (int)nb;
		ps->a->size++;
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	add_arguments_in_stack(t_push_swap *ps, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		split_and_add_in_stack(ps->a, av[i]);
		i++;
	}
}
