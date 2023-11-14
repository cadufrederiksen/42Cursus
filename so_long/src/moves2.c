/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:00:05 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/14 15:17:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up2(t_data *data)
{
	if (data->map[data->y - 1][data->x] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("Total moves: %d\n", ++data->total_moves);
	}
}

void	move_down2(t_data *data)
{
	if (data->map[data->y + 1][data->x] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("Total moves: %d\n", ++data->total_moves);
	}
}

void	move_left2(t_data *data)
{
	if (data->map[data->y][data->x - 1] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("Total moves: %d\n", ++data->total_moves);
	}
}

void	move_right2(t_data *data)
{
	if (data->map[data->y][data->x + 1] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("Total moves: %d\n", ++data->total_moves);
	}
}
