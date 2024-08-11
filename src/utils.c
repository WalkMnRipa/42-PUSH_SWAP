/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:19:55 by jcohen            #+#    #+#             */
/*   Updated: 2024/08/11 18:41:38 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printf_art(void)
{
	ft_printf(" _____ _____ _____ _____    _____ _ _ _ _____ _____ \n");
	ft_printf("|  _  |  |  |   __|  |  |  |   __| | | |  _  |  _  |\n");
	ft_printf("|   __|  |  |__   |     |  |__   | | | |     |   __|\n");
	ft_printf("|__|  |_____|_____|__|__|  |_____|_____|__|__|__|   \n");
	ft_printf("                                                    \n");
}

void	ft_cleanup_and_print_error(t_push_swap *ps, char *error)
{
	ft_printf("%s\n", error);
	free_push_swap(ps);
	exit(0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
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
