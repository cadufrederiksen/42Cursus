/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:59 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/09 12:57:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks_check()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int i;
	t_data *data;

	atexit(leaks_check);
	data = malloc(sizeof(t_data));
	if(!data)
		return(0);
	init_var(data);
	if (argc != 2)
		return(2);
	i = ft_strlen(argv[1]) - 1;
	if(argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b' && argv[1][i - 3] == '.')
	{
		if(!map_check(argv[1], data))//quando sai daqui o mapa ja esta em **map e ja foi checkado
			return(ft_free(data), 2);//se isso falhaar tenho que livrar memória 
	}
	else 
		return(ft_printf("Error: Wrong map name"), 2);
	init_game(data);
	return(ft_free(data), free(data), 0);
}
