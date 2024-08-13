/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:41:46 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/13 17:06:19 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sort_four(t_push_swap *ps)
{
	int	min_index;

	min_index = find_min_index(ps->a, ps->a->size);
	while (min_index > 0)
	{
		ft_ra(ps);
		min_index--;
	}
	ft_pb(ps);
	sort_three(ps);
	ft_pa(ps);
}

void	sort_five(t_push_swap *ps)
{
	int	min_index;
	int	i;

	i = 0;
	while (i < 2)
	{
		min_index = find_min_index(ps->a, ps->a->size);
		while (min_index > 0)
		{
			ft_ra(ps);
			min_index--;
		}
		ft_pb(ps);
		i++;
	}
	sort_three(ps);
	ft_pa(ps);
	ft_pa(ps);
}

void	sort_small_set(t_push_swap *ps)
{
	if (ps->a->size == 2)
		sort_two(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else if (ps->a->size == 4)
		sort_four(ps);
	else if (ps->a->size == 5)
		sort_five(ps);
}
