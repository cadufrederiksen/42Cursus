/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:42:42 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/19 13:05:23 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *game)
{
	game->player.pos_y -= 0.5;
	//printf("%f\n", game->player.pos_y);
}

void	move_down(t_game *game)
{
	game->player.pos_y += 0.5;
	//printf("%f\n", game->player.pos_y);
}

void	move_left(t_game *game)	
{
	game->player.pos_x -= 0.5;//solo me movimiento por los bordes
	//printf("%f\n", game->player.pos_x);
}

void	move_right(t_game *game)
{
	game->player.pos_x += 0.5;
	//printf("%f\n", game->player.pos_x);
}

void	moves(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	
	game = param;
	printf("dirx = %f", game->player.dir_x);
	printf("diry = %f\n", game->player.dir_y);
	printf("x = %f ", game->player.pos_x);
	printf("y = %f\n", game->player.pos_y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_up(game);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_down(game);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_left(game);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
 		move_right(game);
/* 	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT) && 
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		 */
		
}