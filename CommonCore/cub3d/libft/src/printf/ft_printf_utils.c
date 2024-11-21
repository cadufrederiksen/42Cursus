/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:36:34 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 17:07:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_pf(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (*str)
		i += write(fd, str++, 1);
	return (i);
}

int	ft_putptr_pf(unsigned long ptr, int fd)
{
	int		i;

	i = 0;
	i += ft_putstr_pf("0x", fd);
	if (ptr == 0)
		i += ft_putchar_pf('0', fd);
	else
		i += ft_putnbrbase_ptr_pf(ptr, 16, "0123456789abcdef", fd);
	return (i);
}

int	ft_putnbrbase_pf(long n, int base, const char *base_digits, int fd)
{
	int	i;

	if (n < 0)
	{
		write(fd, "-", 1);
		return (ft_putnbrbase_pf(-n, base, base_digits, fd) + 1);
	}
	if (n < base)
		return (ft_putchar_pf(base_digits[n], fd));
	else
	{
		i = ft_putnbrbase_pf(n / base, base, base_digits, fd);
		return (i + ft_putnbrbase_pf(n % base, base, base_digits, fd));
	}
}

int	ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits,
	int fd)
{
	int	i;

	if (n < (unsigned long) base)
		return (ft_putchar_pf(base_digits[n], fd));
	else
	{
		i = ft_putnbrbase_ptr_pf(n / base, base, base_digits, fd);
		return (i + ft_putnbrbase_ptr_pf(n % base, base, base_digits, fd));
	}
}
