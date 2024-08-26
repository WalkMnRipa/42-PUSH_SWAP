/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:10:25 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/26 19:07:33 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_input(int ac, char **av)
{
	char	**split;
	int		j;

	while (ac > 1)
	{
		split = ft_split(av[ac - 1], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_valid(split[j]))
			{
				ft_free_split(split);
				return (0);
			}
			j++;
		}
		ft_free_split(split);
		ac--;
	}
	return (1);
}

static t_push_swap	*init_all(int ac, char **av)
{
	int			total_numbers;
	t_push_swap	*ps;

	total_numbers = count_total_numbers(ac, av);
	if (total_numbers <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	ps = init_push_swap(total_numbers);
	if (!ps)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (ps);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return (0);
	if (!is_valid_input(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ps = init_all(ac, av);
	if (!ps || !parse_arguments(ps, ac, av))
		return (ft_cleanup_and_print_error(ps), 1);
	if (!is_sorted_start(ps->a))
	{
		if (ps->a->size <= 5)
			sort_small_set(ps);
		else
		{
			simplify_stack(ps);
			radix_sort(ps);
		}
	}
	free_push_swap(ps);
	return (0);
}
