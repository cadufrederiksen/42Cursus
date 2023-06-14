/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:33:10 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/23 16:26:42 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*b;

	i = 0;
	b = s;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}

/* int main ()
{
   char s[] = "hola";
   size_t n = 1;
   ft_bzero(s, n); 
   //bzero(s, n);
   printf("%s", s);
} */