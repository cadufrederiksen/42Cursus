/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:52:35 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/05 10:55:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_sort_params(int argc, char **argv, int j)//ordena argv
{
	int		i;
	char	*c;

	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) > ft_atoi(argv[i])) 
			{
				c = argv[i];
				argv[i] = argv[j];
				argv[j] = c;
				i++;
			}
			else
				i++;
		}
		j++;
	}
	return (argv);
}

int new_argc(char **argv)
{
	int x;

	x = 0;
	while(argv[x])
		x++;
	return(x);
}