/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:54:50 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/10 17:57:19 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		size;
	int		i;

	if (!format)
		return (-1);
	va_start(arg_ptr, format);
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_make_conversion(format[i], arg_ptr);
		}
		else
		{
			ft_putchar(format[i]);
			size++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (size);
}
