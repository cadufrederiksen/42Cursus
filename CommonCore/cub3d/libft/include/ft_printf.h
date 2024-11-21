/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:01:37 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 17:52:26 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_fprintf(int fd, char const *format, ...);
int	print_format(char format, va_list *ap, int fd);
int	ft_putchar_pf(int c, int fd);
int	ft_putstr_pf(char *str, int fd);
int	ft_putptr_pf(unsigned long ptr, int fd);
int	ft_putnbrbase_pf(long n, int base, const char *base_digits, int fd);
int	ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits,
		int fd);

#endif
