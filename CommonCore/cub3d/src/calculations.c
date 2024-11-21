/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:32:26 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/19 15:26:40 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_direction(t_game *game, int x)
{
	double	camera_x; //x es la columna que esta generando el rayo

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	game->ray.raydir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.raydir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
}

void	calculate_delta_dist(t_game *game)
{	// para evitar dividir por 0, evita posibles errores cuando el rayo es paralelo a un eje
	if (game->ray.raydir_x == 0)
		game->ray.deltadist_x = 1e30;
	else
		game->ray.deltadist_x = fabs(1 / game->ray.raydir_x); //numero absoluto

	if (game->ray.raydir_y == 0)
		game->ray.deltadist_y = 1e30;
	else
		game->ray.deltadist_y = fabs(1 / game->ray.raydir_y);
}

void	calculate_perp_wall_dist(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.perp_walldist = (game->ray.map_x - game->player.pos_x + \
		(1 - game->ray.step_x) / 2) / game->ray.raydir_x;
	}
	else
	{
		game->ray.perp_walldist = (game->ray.map_y - game->player.pos_y + \
		(1 - game->ray.step_y) / 2) / game->ray.raydir_y;
	}
}

void	calculate_draw_limits(t_game *game)
{
	if (game->ray.perp_walldist == 0)
		game->ray.perp_walldist = 1e-6; // Evitar división por 0
	game->ray.line_height = (int)(SCREEN_HEIGHT / game->ray.perp_walldist);
	game->ray.draw_start = -game->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->ray.draw_end >= SCREEN_HEIGHT)
		game->ray.draw_end = SCREEN_HEIGHT - 1;
}
