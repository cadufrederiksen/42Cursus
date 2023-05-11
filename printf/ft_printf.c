/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:42:22 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/11 16:16:44 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_checktype(va_list arg, char type)
{
	int	resultlen;

	resultlen = 0;
	if (type == 'c')
		resultlen += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		resultlen += ft_putstr(va_arg(arg, char *));
	else if (type == 'p')
		resultlen += ft_putptr(va_arg(arg, unsigned long long));
	else if (type == 'd' || type == 'i')
		resultlen += ft_putnbr(va_arg(arg, int));
	else if (type == 'u')
		resultlen += ft_putunbr(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X')
		resultlen += ft_printhex(va_arg(arg, unsigned int), type);
	else if (type == '%')
		resultlen += ft_printsimbol();
	return (resultlen);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		resultlen;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	resultlen = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			resultlen += ft_checktype(arg, str[i]);
		}
		else
			resultlen += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (resultlen);
}

/* int	main(void)
{
	//int x = 10;
	//int *p = &x;

	ft_printf(" %p %p \n", -184, 18);
	printf(" %p %p ", (void *)-184, (void*)184);
	//printf("Hola que tal %% %d", -432);
}   */