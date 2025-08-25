/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:36:58 by hemaciel          #+#    #+#             */
/*   Updated: 2025/08/25 12:53:21 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	put_pointer(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr_fd(1, "(nil)"));
	i += ft_putstr_fd(1, "0x");
	i += ft_puthex((size_t)ptr, 0);
	return (i);
}

static int	putstr(char *str)
{
	if (!str)
		return (ft_putstr_fd(1, "(null)"));
	else
		return (ft_putstr_fd(1, str));
}

static int	conversion(char *c, va_list arg)
{
	if (*c == 'c')
		return (ft_putchar_fd (1, (char)(va_arg (arg, int))));
	if (*c == 's')
		return (putstr(va_arg(arg, char *)));
	if (*c == 'p')
		return (put_pointer(va_arg(arg, void *)));
	if ((*c == 'd') || (*c == 'i'))
		return (ft_putnbr(va_arg(arg, int)));
	if (*c == 'u')
		return (ft_putnbr_u((unsigned int)va_arg(arg, unsigned int)));
	if (*c == 'x')
		return (ft_puthex((unsigned int)va_arg(arg, int), 0));
	if (*c == 'X')
		return (ft_puthex((unsigned int)va_arg(arg, int), 1));
	if (*c == '%')
		return (ft_putchar_fd(1, '%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		total;

	total = 0;
	if (!format)
		return (-1);
	if (!format[0])
		return (0);
	va_start (ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total += conversion((char *)format, ptr);
		}
		else
			total += ft_putchar_fd(1, *format);
		format++;
	}
	va_end(ptr);
	return (total);
}
