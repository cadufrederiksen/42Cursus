/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:59 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/05 12:51:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	init_var(data);
	if (argc != 2)
		return (2);
	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b'
		&& argv[1][i - 3] == '.')
	{
		//printf("aqui\n");
		if (!map_check(argv[1], data))
			exit(2);
	}
	else
		return (ft_printf("Error: Wrong map name\n"), free(data), 2);
	if (!init_game(data))
		return (ft_printf("Problem creating images\n"), 0);
	return (free(data->text), free(data->img), ft_map_free(data),
		free(data), 0);
}
