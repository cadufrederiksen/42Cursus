/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/29 10:26:06 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 	if(!check_all(argv, checker))
	{
		write(1, "Error\n", 6);
		return(0);
	} 
	push_swap(argc, argv, checker);
	system("leaks push_swap");
	return(0);
}
