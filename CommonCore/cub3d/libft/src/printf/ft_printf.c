/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:01:43 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 17:07:09 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list *ap, int fd)
{
	int			i;

	i = 0;
	if (format == 'c')
		i += ft_putchar_pf(va_arg(*ap, int), fd);
	else if (format == 's')
		i += ft_putstr_pf(va_arg(*ap, char *), fd);
	else if (format == 'p')
		i += ft_putptr_pf(va_arg(*ap, unsigned long), fd);
	else if (format == 'd' || format == 'i')
		i += ft_putnbrbase_pf((long)va_arg(*ap, int), 10, \
		"0123456789", fd);
	else if (format == 'u')
		i += ft_putnbrbase_pf((long)va_arg(*ap, unsigned int), 10, \
		"0123456789", fd);
	else if (format == 'x')
		i += ft_putnbrbase_pf((long)va_arg(*ap, unsigned int), 16, \
		"0123456789abcdef", fd);
	else if (format == 'X')
		i += ft_putnbrbase_pf((long)va_arg(*ap, unsigned int), 16, \
		"0123456789ABCDEF", fd);
	else
		i += write(fd, &format, 1);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	while (*format)
	{
		if (*format == '%')
			i += print_format(*(++format), &ap, 1);
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (i);
}

int	ft_fprintf(int fd, char const *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	if (write(fd, "", 0) == -1)
		return (-1);
	i = 0;
	while (*format)
	{
		if (*format == '%')
			i += print_format(*(++format), &ap, fd);
		else
			i += write(fd, format, 1);
		++format;
	}
	va_end(ap);
	return (i);
}
