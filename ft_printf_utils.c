/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:08:48 by hemaciel          #+#    #+#             */
/*   Updated: 2025/08/25 10:12:35 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int fd, char c)
{
	int	total;

	total = write (fd, &c, 1);
	return (total);
}

int	ft_putstr_fd(int fd, char *str)
{
	int	total;

	total = 0;
	while (*str)
		total += write(fd, str++, 1);
	return (total);
}

int	ft_putnbr(int n)
{
	int		i;
	long	ln;

	i = 0;
	ln = n;
	if (ln < 0)
	{
		i += ft_putchar_fd(1, '-');
		ln = -ln;
	}
	if (ln >= 10)
		i += ft_putnbr(ln / 10);
	i += ft_putchar_fd(1, ln % 10 + '0');
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putchar_fd(1, n % 10 + '0');
	return (i);
}

int	ft_puthex(size_t n, char to_upper)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_puthex(n / 16, to_upper);
	if (to_upper)
		i += ft_putchar_fd(1, "0123456789ABCDEF"[n % 16]);
	else
		i += ft_putchar_fd(1, "0123456789abcdef"[n % 16]);
	return (i);
}
