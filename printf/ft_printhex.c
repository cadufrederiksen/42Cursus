#include "ft_printf.h"

int	count_nhex(long n)
{
	size_t	size;

	size = 0;
	if (n > 16)
	{
		while (n != 0)
		{
			size++;
			n /= 16;
		}
	}
	else
		size++;
	return (size);
}

int ft_printhex(unsigned int n, char  type)
{
    char *base;
    long nbr;

    nbr = n;
    if (type == 'X')
        base = "0123456789ABCDEF";
    else 
        base = "0123456789abcdef";
    if (nbr > 15)
    {
        ft_printhex(nbr / 16, type);
        nbr %= 16;
    }
    write(1, &base[nbr], 1);
    return(count_nhex(n));
}

void recursive_ptr(long nbr, char *base)
{
    
    if (nbr > 15)
    {
        recursive_ptr(nbr / 16, base);
        nbr %= 16;
    }
    write(1, &base[nbr], 1);
}
int ft_putptr(unsigned long n)
{
    char *base;
    long nbr;

    nbr = n;
    base = "0123456789abcdef";
    write(1, "0x", 2);
    recursive_ptr(nbr, base);
    return(count_nhex(n) + 2);
}
