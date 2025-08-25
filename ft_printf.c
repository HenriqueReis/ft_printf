/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:36:58 by hemaciel          #+#    #+#             */
/*   Updated: 2025/08/25 08:17:03 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	*ptr;
	int	total;
	
	total = 0;
	if (!format)
		return (-1);
	if (format[0] == '\0')
		return (0);
	va_start (ptr, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);// DEFINIR MELHOR ESSE PUTCHAR
			total++;
		}
		else if (*format == '%')
			total++;
			// tratar as conversões
        }
}
