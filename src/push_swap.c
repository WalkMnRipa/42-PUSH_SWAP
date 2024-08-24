/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:10:25 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/24 20:51:28 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	print_tab(t_push_swap *ps)
// {
// 	int	max_size;
// 	int	i;

// 	if (ps->a->size > ps->b->size)
// 		max_size = ps->a->size;
// 	else
// 		max_size = ps->b->size;
// 	printf("^     | ^\n");
// 	i = 0;
// 	while (i < max_size)
// 	{
// 		if (i < ps->a->size)
// 			printf("%-5d", ps->a->stack[i]);
// 		else
// 			printf("     ");
// 		printf(" | ");
// 		if (i < ps->b->size)
// 			printf("%-5d", ps->b->stack[i]);
// 		else
// 			printf("     ");
// 		printf("\n");
// 		i++;
// 	}
// 	printf("----- | -----\n");
// 	printf("  a   |   b\n");
// }

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
	{
		ft_cleanup_and_print_error(ps);
		return (1);
	}
	if (!is_sorted(ps->a))
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
