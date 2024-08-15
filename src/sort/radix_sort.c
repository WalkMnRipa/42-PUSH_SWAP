/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/15 19:13:27 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	normalize_data(t_push_swap *ps)
{
	int	*temp;
	int	*sorted;
	int	tmp;

	int i, j;
	temp = malloc(ps->a->size * sizeof(int));
	sorted = malloc(ps->a->size * sizeof(int));
	if (!temp || !sorted)
		ft_cleanup_and_print_error(ps);
	for (i = 0; i < ps->a->size; i++)
	{
		temp[i] = ps->a->stack[i];
		sorted[i] = ps->a->stack[i];
	}
	for (i = 0; i < ps->a->size - 1; i++)
	{
		for (j = 0; j < ps->a->size - i - 1; j++)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < ps->a->size; i++)
	{
		for (j = 0; j < ps->a->size; j++)
		{
			if (temp[i] == sorted[j])
			{
				ps->a->stack[i] = j;
				break ;
			}
		}
	}
	free(temp);
	free(sorted);
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

	int i, j;
	normalize_data(ps);
	max_bits = get_max_bits(ps);
	size = ps->a->size;
	for (i = 0; i < max_bits; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (get_bit(ps->a->stack[0], i) == 0)
				ft_pb(ps);
			else
				ft_ra(ps);
		}
		while (ps->b->size > 0)
			ft_pa(ps);
	}
}
