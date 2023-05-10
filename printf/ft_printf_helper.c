#include "ft_printf.h"

int ft_putstr(char *str)
{
	int i;

    if (!str)
    {
        write(1, "(NULL)", 6);
        return(6);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return(i);
}

int ft_printsimbol(void)
{
    write(1, "%", 1);
    return(1);
}

