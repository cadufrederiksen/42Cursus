/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:00:05 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/15 10:39:11 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up2(t_data *data)
{
	if (data->map[data->y - 1][data->x] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You won the game!\n");
	}
	if (data->map[data->y - 1][data->x] == 'H')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You lost the game!\n");
	}
}

void	move_down2(t_data *data)
{
	if (data->map[data->y + 1][data->x] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You won the game!\n");
	}
	if (data->map[data->y + 1][data->x] == 'H')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You lost the game!\n");
	}
}

void	move_left2(t_data *data)
{
	if (data->map[data->y][data->x - 1] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You won the game!\n");
	}
	if (data->map[data->y][data->x - 1] == 'H')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You lost the game!\n");
	}
}

void	move_right2(t_data *data)
{
	if (data->map[data->y][data->x + 1] == 'E' && data->col_total == 0)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You won the game!\n");
	}
	if (data->map[data->y][data->x + 1] == 'H')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You lost the game!\n");
	}
}

void	print_moves(t_data *data)
{
	static int	moves = 1;
	char		*str;

	str = ft_itoa(moves);
	if (data->mv_count)
		mlx_delete_image(data->mlx_ptr, data->mv_count);
	data->mv_count = mlx_put_string(data->mlx_ptr, str, 1, 1);
	free(str);
	moves++;
}
