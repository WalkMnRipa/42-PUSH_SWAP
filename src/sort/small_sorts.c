/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:41:46 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/15 19:41:08 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_push_swap *ps)
{
	if (ps->a->stack[0] > ps->a->stack[1])
		ft_sa(ps);
}

void	sort_three(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->stack[0];
	b = ps->a->stack[1];
	c = ps->a->stack[2];
	if (a > b && b < c && a < c)
		ft_sa(ps);
	else if (a > b && b > c)
	{
		ft_sa(ps);
		ft_rra(ps);
	}
	else if (a > b && b < c && a > c)
		ft_ra(ps);
	else if (a < b && b > c && a < c)
	{
		ft_sa(ps);
		ft_ra(ps);
	}
	else if (a < b && b > c && a > c)
		ft_rra(ps);
}

void	sort_small_set(t_push_swap *ps)
{
	int	min_index;

	if (ps->a->size == 2)
		sort_two(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else
	{
		while (ps->a->size > 3)
		{
			min_index = find_min_index(ps->a);
			while (min_index > 0)
			{
				if (min_index <= ps->a->size / 2)
					ft_ra(ps);
				else
					ft_rra(ps);
				min_index = find_min_index(ps->a);
			}
			ft_pb(ps);
		}
		sort_three(ps);
		while (ps->b->size > 0)
			ft_pa(ps);
	}
}
