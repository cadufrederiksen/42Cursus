/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:23:06 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/13 16:23:06 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_n(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n > 9)
	{
		while (n != 0)
		{
			size++;
			n /= 10;
		}
	}
	else
		size++;
	return (size);
}

char	*create_str(long nbr, char *ptr, int size)
{
	size_t	x;

	x = size - 1;
	if (nbr == 0)
		ptr[0] = '0';
	else if (0 > nbr)
	{
		nbr *= -1;
		ptr[0] = '-';
	}
	while (nbr != 0)
	{
		ptr[x] = (nbr % 10) + 48;
		nbr /= 10;
		x--;
	}
	ptr[size] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	size;
	long	nbr;

	nbr = n;
	size = count_n(nbr);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	create_str(nbr, ptr, size);
	return (ptr);
}

/* int	main(void)
{
	int n;
	n = -2147483648;
	printf("%s", ft_itoa(n));
	return (0);
}  */