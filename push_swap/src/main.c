/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/12 11:57:25 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int checker;
	checker = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1] , ' ');
		argc = new_argc(argv);
	}
 	if(!check_all(argv))
	{
		write(1, "Error\n", 6);
		return(0);
	} 
	push_swap(argc, argv, checker);
	return(0);
}
