/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:13:31 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/19 13:28:29 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = tmp;
}

void	ft_sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->stack[0];
	b->stack[0] = b->stack[1];
	b->stack[1] = tmp;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size < 1)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = b->stack[0];
	i = 0;
	while (i < b->size)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	a->size++;
	b->size--;
}

void	ft_pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size < 1)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = a->stack[0];
	i = 0;
	while (i < a->size)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	b->size++;
	a->size--;
}

void	ft_ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->stack[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->size - 1] = tmp;
}

void	ft_rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->stack[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[b->size - 1] = tmp;
}

void	ft_rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->stack[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = tmp;
}

void	ft_rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->stack[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = tmp;
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
