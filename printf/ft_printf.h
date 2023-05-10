#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(char const *str, ...);
int ft_checktype(va_list arg, char type);
int	ft_putnbr(int n);
int ft_printsimbol(void);
int ft_putstr(char *str);
int ft_printhex(unsigned int n, char  type);
int ft_putunbr(unsigned int);
int ft_putptr(unsigned long n);

#endif