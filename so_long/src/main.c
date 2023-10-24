/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:59 by carmarqu          #+#    #+#             */
/*   Updated: 2023/10/24 16:33:47 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include "get_next_line.h"

void init_var(t_data *data)
{
	data->ver_len = 0;
	data->hor_len = 0;
	data->col_total = 0;
	data->flag_e = 0;
	data->flag_p = 0;
} 

void	resize_ptr(int32_t width, int32_t height, void* param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);//MLX_STRETCH_IMAGE diz se a janela deve ou nao reajustarse, quando mudamos para um dizemos que sim
}

void init_game(t_data *data)
{
	data->mlx_ptr = mlx_init(1980, 1080, "so_long", NULL);
	mlx_resize_hook(data->mlx_ptr, &resize_ptr, data);//alguma coisa está errada
	//mlx_key_hook(data->mlx_ptr, &key_press, NULL);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	int i;
	int x;
	t_data *data;

	x = 0;
	data = malloc(sizeof(t_data));
	if(!data)
		return(0);
	init_var(data); //inicaliza as variaveis em 0
	if (argc != 2)
		return (0);
	i = ft_strlen(argv[1]) - 1;
	if(argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b' && argv[1][i - 3] == '.')
	{
		ft_printf("%s\n", argv[1]);
		if(!map_check(argv[1], data))//quando sai daqui o mapa ja esta em **map e ja foi checkado
			return(0);
	}
	init_game(data);
	while(x < data->ver_len)
	{
		ft_printf("%s\n", data->map[x]);
		x++;
	}
	return(0);
}