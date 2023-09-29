/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:43:11 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/11 16:05:23 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(char const *str, ...);
int	ft_checktype(va_list arg, char type);
int	ft_putnbr(int n);
int	ft_printsimbol(void);
int	ft_putstr(char *str);
int	ft_printhex(unsigned int n, char type);
int	ft_putunbr(unsigned int n);
int	ft_putptr(unsigned long long n);

#endif