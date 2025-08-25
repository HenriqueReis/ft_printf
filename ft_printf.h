/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:43:48 by hemaciel          #+#    #+#             */
/*   Updated: 2025/08/25 08:53:06 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(int fd, char c);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putstr_fd(int fd, char *str);
int	ft_puthex(size_t n, char to_upper);
#endif
