/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/26 17:24:09 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simplify_stack(t_push_swap *ps)
{
	int		i;
	int		j;
	int		rank;
	long	*copy;

	copy = malloc(sizeof(long) * ps->a->size);
	if (!copy)
		ft_cleanup_and_print_error(ps);
	i = -1;
	while (++i < ps->a->size)
		copy[i] = (long)ps->a->stack[i];
	i = -1;
	while (++i < ps->a->size)
	{
		rank = 0;
		j = -1;
		while (++j < ps->a->size)
			if (copy[j] > copy[i] || (j > i && copy[j] == copy[i]))
				rank++;
		ps->a->stack[i] = rank;
	}
	free(copy);
}

int	get_max_bites(int max)
{
	int	bits;

	bits = 1;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_sort_stack_b(t_push_swap *ps, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_sorted(ps->a))
	{
		if (((ps->b->stack[0] >> j) & 1) == 0)
			ft_rb(ps);
		else
			ft_pa(ps);
	}
	if (is_sorted(ps->a))
		while (ps->b->size != 0)
			ft_pa(ps);
}

void	radix_sort(t_push_swap *ps)
{
	int	size;
	int	max_bits;
	int	i;

	max_bits = get_max_bites(ps->a->size - 1);
	i = 0;
	while (i <= max_bits)
	{
		size = ps->a->size;
		while (size-- && !is_sorted(ps->a))
		{
			if (((ps->a->stack[0] >> i) & 1) == 0)
				ft_ra(ps);
			else
				ft_pb(ps);
		}
		radix_sort_stack_b(ps, ps->b->size, max_bits, i);
		while (ps->b->size)
			ft_pa(ps);
		i++;
	}
}
