/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:34:11 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/20 15:02:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_step_and_side_dist(t_game *game)
{
	if (game->ray.raydir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.pos_x - game->ray.map_x) * game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.pos_x) * game->ray.deltadist_x;
	}
	if (game->ray.raydir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.pos_y - game->ray.map_y) * game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.pos_y) * game->ray.deltadist_y;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		//ft_printf("Checking map at (%d, %d): %c\n",
                  //game->ray.map_x, game->ray.map_y, game->mapsets->map[game->ray.map_y][game->ray.map_x]);
		if (game->mapsets->map[game->ray.map_y][game->ray.map_x] == '1')
			hit = 1;
	}
}

// calcular las coordenadas de la textura y extraer los píxeles
void	draw_column(t_game *game, int x)
{
	int	y;
	int	color;
	
	if (game->ray.side == 0)
		color = 0xFF0000; // Rojo si golpea en un eje X
	else
		color = 0x00FF00; // Verde si golpea en un eje Y
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		//mlx_image_to_window(game->mlx, game->pngs->player, x, y);
		put_pixel_to_image(game->img, x, y, color);
		y++;
	}
}

// Launch a ray to calculate an intersection with the walls
void	cast_ray(t_game *game, int x)
{
	calculate_ray_direction(game, x);
	calculate_delta_dist(game);
	initialize_step_and_side_dist(game);
	perform_dda(game);
	calculate_perp_wall_dist(game);
	calculate_draw_limits(game);
	//ft_printf("Ray %d: draw_start=%d, draw_end=%d, perp_dist=%f\n",
              //x, game->ray.draw_start, game->ray.draw_end, game->ray.perp_walldist);
	//output: Ray 799: draw_start=300, draw_end=300, perp_dist=f
	draw_column(game, x);
}

// Renderiing the full frame
void	draw_frame(t_game *game)
{
	int	x;

	clear_image(game->img); // Clean the image before drawing
	// Launch a ray for each column of pixels
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_ray(game, x);
		x++;
	}
	// Update the window with the rendered image
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
