/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:19:55 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/23 18:02:39 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cleanup_and_print_error(t_push_swap *ps)
{
	ft_putstr_fd("Error\n", 2);
	if (ps)
		free_push_swap(ps);
	exit(1);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_total_numbers(int ac, char **av)
{
	int		total_numbers;
	char	**split;
	int		i;
	int		j;

	total_numbers = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			if (is_valid(split[j]))
				total_numbers++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (total_numbers);
}

int	find_max(t_stack *a)
{
	int	max;
	int	i;

	max = a->stack[0];
	i = 1;
	while (i < a->size)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	return (max);
}

int	find_minValue_ReturnIndex(t_stack *stack)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] < stack->stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
