/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/05 12:25:05 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->y - 1][data->x] == '0')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			data->x * 32, (data->y - 1) * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		data->y--;
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else if (data->map[data->y - 1][data->x] == 'C')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			data->x * 32, (data->y - 1) * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		data->col_total--;
		data->y--;
		data->map[data->y][data->x] = '0';
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else
		move_up2(data);
}

void	move_down(t_data *data)
{
	if (data->map[data->y + 1][data->x] == '0')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			data->x * 32, (data->y + 1) * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		data->y++;
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else if (data->map[data->y + 1][data->x] == 'C')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			data->x * 32, (data->y + 1) * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		data->col_total--;
		data->y++;
		data->map[data->y][data->x] = '0';
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else
		move_down2(data);
}

void	move_left(t_data *data)
{
	if (data->map[data->y][data->x - 1] == '0')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main_r,
			(data->x - 1) * 32, data->y * 32);
		data->x--;
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else if (data->map[data->y][data->x - 1] == 'C')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main_r,
			(data->x - 1) * 32, data->y * 32);
		data->col_total--;
		data->x--;
		data->map[data->y][data->x] = '0';
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else
		move_left2(data);
}

void	move_right(t_data *data)
{
	if (data->map[data->y][data->x + 1] == '0')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			(data->x + 1) * 32, data->y * 32);
		data->x++;
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else if (data->map[data->y][data->x + 1] == 'C')
	{
		mlx_image_to_window(data->mlx_ptr, data->img->floor,
			data->x * 32, data->y * 32);
		mlx_image_to_window(data->mlx_ptr, data->img->main_l,
			(data->x + 1) * 32, data->y * 32);
		data->col_total--;
		data->x++;
		data->map[data->y][data->x] = '0';
		data->total_moves++;
		ft_printf("Total moves: %d\n", data->total_moves);
	}
	else
		move_right2(data);
}

void	moves(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	data->map[data->y][data->x] = '0';
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx_ptr);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_down(data);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(data);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(data);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_right(data);
}
