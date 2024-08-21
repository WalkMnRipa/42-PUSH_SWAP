/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/21 21:23:29 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	normalize_data(t_push_swap *ps)
{
	int	*temp;
	int	*ranks;
	int	i;
	int	j;
	int	rank;

	temp = malloc(ps->a->size * sizeof(int));
	ranks = malloc(ps->a->size * sizeof(int));
	ft_copy_stack(ps->a->stack, temp, ps->a->size);
	i = 0;
	while (i < ps->a->size)
	{
		rank = 0;
		j = 0;
		while (j < ps->a->size)
		{
			if (temp[j] < temp[i] || (temp[j] == temp[i] && j < i))
				rank++;
			j++;
		}
		ranks[i] = rank;
	}
	i = 0;
	while (i < ps->a->size)
	{
		ps->a->stack[i] = ranks[i];
		i++;
	}
	free(temp);
	free(ranks);
}

int	get_bit(int num, int pos)
{
	return ((num >> pos) & 1);
}

int	get_max_bits(t_push_swap *ps)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = ps->a->size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_push_swap *ps)
{
	int	max_bits;
	int	size;
	int	i;
	int	bit;

	normalize_data(ps);
	bit = 0;
	max_bits = get_max_bits(ps);
	size = ps->a->size;
	i = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((ps->a->stack[0] & (1 << bit)) == 0)
				ft_pb(ps);
			else
				ft_ra(ps);
			i++;
		}
		while (ps->b->size > 0)
			ft_pa(ps);
		bit++;
	}
}
