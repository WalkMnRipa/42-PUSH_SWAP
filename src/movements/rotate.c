/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:04:23 by jcohen            #+#    #+#             */
/*   Updated: 2024/09/08 17:00:26 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->a->stack[ps->a->size - 1] = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->b->stack[ps->b->size - 1] = tmp;
	ft_printf("rb\n");
}

void	ft_rr(t_push_swap *ps)
{
	ft_ra(ps);
	ft_rb(ps);
	ft_printf("rr\n");
}
