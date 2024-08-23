/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/23 18:53:22 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simplify_stack(t_push_swap *ps)
{
	int	index;
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * ps->a->size);
	if (!copy)
		ft_cleanup_and_print_error(ps);
	ft_copy_stack(copy, ps->a->stack, ps->a->size);
	bubble_sort(copy, ps->a->size);
	i = 0;
	while (i < ps->a->size)
	{
		index = find_index_in_stack(copy, ps->a->size, ps->a->stack[i]);
		ps->a->stack[i] = index;
		i++;
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

void	radix_sort(t_push_swap *ps)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ps->a->size;
	max_bits = get_max_bites(ps->a->size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((ps->a->stack[0] & (1 << i)) == 0)
				ft_ra(ps);
			else
				ft_pb(ps);
			j++;
		}
		while (ps->b->size)
			ft_pa(ps);
		i++;
	}
}
