/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:02:57 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/09 13:29:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_var(t_data *data)
{
	data->ver_len = 0;
	data->hor_len = 0;
	data->col_total = 0;
	data->flag_e = 0;
	data->flag_p = 0;
	data->ff_c = 0;
	data->ff_e = 0;
	data->total_moves = 0;
} 

void resize_ptr(int32_t width, int32_t height, void* param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);//MLX_STRETCH_IMAGE diz se a janela deve ou nao reajustarse, quando mudamos para um dizemos que sim
}

void init_game(t_data *data)
{
	data->mlx_ptr = mlx_init(data->hor_len * 32, data->ver_len * 32, "so_long", 1); //*32 para terem um mesmo tamanho
	mlx_resize_hook(data->mlx_ptr, &resize_ptr, data);
	mlx_key_hook(data->mlx_ptr, &moves, data);
	if(!create_text(data))
	{
		ft_free(data);
		//free(data);
		exit(2);
	}
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
}

void ft_free(t_data *data)
 {
	if(data->text != NULL)
		free(data->text);
 	if(data->img != NULL)
		free(data->img); 
	while(data->ver_len-- > 0)
	{
		if (data->map[data->ver_len])
			free(data->map[data->ver_len]);
	}
	free(data->map);
}
