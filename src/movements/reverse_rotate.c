/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:08:43 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/13 16:06:59 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[ps->a->size - 1];
	i = ps->a->size - 1;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[0] = tmp;
	ft_printf("rra\n");
}

void	ft_rrb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[ps->b->size - 1];
	i = ps->b->size - 1;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[0] = tmp;
	ft_printf("rrb\n");
}

void	ft_rrr(t_push_swap *ps)
{
	ft_rra(ps);
	ft_rrb(ps);
	ft_printf("rrr\n");
}
