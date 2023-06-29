/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:38:07 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/28 12:39:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(char **argv)
{
	int i;
	int x;
	
	x = 1;
	while(argv[x])
	{
		i = 0;
		while(argv[x][i])
		{
			if((argv[x][i] < '0' || argv[x][i] > '9') && argv[x][i] != '-')	
				return(0);
			else 
				i++;
		}		
		x++;
	}
	x = 1;
	while (argv[x])
	{
		i = x + 1;
		while(argv[i])
		{
			if(ft_atoi(argv[x]) == ft_atoi(argv[i]))
				return(0);
			i++;
		}
		x++;
	}
	return(1);
}

