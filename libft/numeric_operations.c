/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:54:39 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/10 17:57:32 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_strlen_printf(const char *str)
{
	int	len_str;

	len_str = 0;
	while (str[len_str] != '\0')
		len_str++;
	return (len_str);
}

int	ft_putnbr_long(long n)
{
	int	size;

	size = 0;
	if (n >= 10)
		size += ft_putnbr_long(n / 10);
	ft_putchar(n % 10 + '0');
	size++;
	return (size);
}
