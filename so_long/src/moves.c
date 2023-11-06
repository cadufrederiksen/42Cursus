/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/06 16:47:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void move_up(t_data *data)
{
	if(data->map[data->y - 1][data->x] != '1' && data->y - 1 > 0)
	{
		ft_printf("x = %d y = %d", data->x, data->y);
		mlx_image_to_window(data->mlx_ptr, data->img->main, data->x * 32, (data->y - 1) * 32);	
		mlx_image_to_window(data->mlx_ptr, data->img->floor, data->x * 32, data->y * 32);	
		data->y--;
	}
}

void move_down(t_data *data)
{
	if(data->map[data->y + 1][data->x] != '1' && data->y + 1 < (data->ver_len - 1))
	{
		ft_printf("x = %d y = %d", data->x, data->y);
		mlx_image_to_window(data->mlx_ptr, data->img->main, data->x * 32, (data->y + 1) * 32);	
		mlx_image_to_window(data->mlx_ptr, data->img->floor, data->x * 32, data->y * 32);	
		data->y++;
	}
}

void move_left(t_data *data)
{
	if(data->map[data->y][data->x - 1] != '1' && data->x - 1 > 0)
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor, data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main, (data->x - 1) * 32, data->y * 32);
		data->x--;
	}	
}

void move_right(t_data *data)
{
	if(data->map[data->y][data->x + 1] != '1' && data->x + 1 < (data->hor_len - 1))
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor, data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main, (data->x + 1) * 32, data->y * 32);
		data->x++;
	}	
}

void moves(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = param; 
	if((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_down(data);
	if((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		move_up(data);
	if((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_left(data); 
	if((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_right(data);
}

