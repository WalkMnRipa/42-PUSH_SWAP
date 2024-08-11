/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:10:25 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/11 21:17:06 by jcohen           ###   ########.fr       */
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

static t_push_swap	*init_all(int ac, char **av)
{
	int			total_numbers;
	t_push_swap	*ps;

	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [numbers]\n");
		return (NULL);
	}
	total_numbers = count_total_numbers(ac, av);
	if (total_numbers <= 0)
	{
		ft_printf("Error\nNo numbers to sort\n");
		return (NULL);
	}
	ps = init_push_swap(total_numbers);
	if (!ps)
	{
		ft_printf("Error\nInit failed\n");
		return (NULL);
	}
	return (ps);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	ps = init_all(ac, av);
	if (!ps)
		return (1);
	if (!parse_arguments(ps, ac, av))
	{
		ft_cleanup_and_print_error(ps, "Error\nParsing failed");
		return (1);
	}
	ft_printf_art();
	print_tab(ps);
	free_push_swap(ps);
	return (0);
}

/*
 *
 *  +------------+
 *  |   Début    |
 *  +------------+
 *         |
 *         v
 *  +------------------------+
 *  | Initialisation/Parsing |
 *  +------------------------+
 *         |
 *         v
 *  +-------------------------+
 *  | Nombre d'éléments <= 5? |
 *  +-------------------------+
 *     |              |
 *    Oui            Non
 *     |              |
 *     v              v
 *  +-----------+  +----------------+
 *  |Sort Small |  | Normalize Data |
 *  |    Set    |  +----------------+
 *  +-----------+         |
 *     |                  v
 *     |           +---------------+
 *     |           |   Radix Sort  |
 *     |           +---------------+
 *     |                  |
 *     |                  |
 *     |        +-------------------+
 *     +------->| Afficher Résultat |
 *              +-------------------+
 *                       |
 *                       v
 *                 +------------+
 *                 |    Fin     |
 *                 +------------+
 */