/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:10:25 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/11 19:21:41 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_tab(t_push_swap *ps)
{
	int	max_size;
	int	i;

	if (ps->a->size > ps->b->size)
		max_size = ps->a->size;
	else
		max_size = ps->b->size;
	printf("^     | ^\n");
	i = 0;
	while (i < max_size)
	{
		if (i < ps->a->size)
			printf("%-5d", ps->a->stack[i]);
		else
			printf("     ");
		printf(" | ");
		if (i < ps->b->size)
			printf("%-5d", ps->b->stack[i]);
		else
			printf("     ");
		printf("\n");
		i++;
	}
	printf("----- | -----\n");
	printf("  a   |   b\n");
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;
	int			total_numbers;

	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [numbers]\n");
		return (0);
	}
	total_numbers = count_total_numbers(ac, av);
	if (total_numbers <= 0)
	{
		ft_printf("Error\nNo numbers to sort\n");
		return (1);
	}
	ps = init_push_swap(total_numbers);
	if (!ps)
	{
		ft_cleanup_and_print_error(ps, "Error\nInit failed");
		return (1);
	}
	if (!parse_arguments(ps, ac, av))
	{
		ft_cleanup_and_print_error(ps, "Error\nParsing failed");
		return (1);
	}
	print_tab(ps);
	free_push_swap(ps);
	return (0);
}
