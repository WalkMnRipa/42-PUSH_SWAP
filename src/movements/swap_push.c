/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:57:09 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/11 21:47:32 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_push_swap *ps)
{
	int	tmp;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	ps->a->stack[0] = ps->a->stack[1];
	ps->a->stack[1] = tmp;
}

void	ft_sb(t_push_swap *ps)
{
	int	tmp;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	ps->b->stack[0] = ps->b->stack[1];
	ps->b->stack[1] = tmp;
}

void	ft_ss(t_push_swap *ps)
{
	ft_sa(ps);
	ft_sb(ps);
}

void	ft_pa(t_push_swap *ps)
{
	int	i;

	if (ps->b->size == 0)
		return ;
	i = ps->a->size;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[0] = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->a->size++;
	ps->b->size--;
}

void	ft_pb(t_push_swap *ps)
{
	int	i;

	if (ps->a->size == 0)
		return ;
	i = ps->b->size;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[0] = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->b->size++;
	ps->a->size--;
}
