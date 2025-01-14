/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 15:06:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **str)
{
	int x;
	
	x = 0;
	while (str[x])
		x++;
	while (x >= 0)
		free(str[x--]);
	free(str);
}

int main(int argc, char **argv)
{
	int checker;
	
	checker = argc;
	if(argc <= 1)	
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1] , ' ');
		argc = new_argc(argv);// aqui recorre todos os números
	}
	push_swap(argc, argv, checker);
	if (checker == 2)
		free_2d(argv);
	return(0);
}
