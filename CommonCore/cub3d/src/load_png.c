/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:29:28 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/21 15:45:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img *load_png(t_game *game)
{
	t_img *img;
	if (!game || !game->mlx || !game->textures || !game->textures->player)
	{
		ft_fprintf(2, "Error: Invalid parameters passed to load_png\n");
		return (NULL);
	}
	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_fprintf(2, "Error: Failed to allocate memory for image\n");
		return (NULL);
	}
	img->player = mlx_texture_to_image(game->mlx, game->textures->player);
	if (!img->player)
	{
		ft_fprintf(2, "Error: Failed to convert texture to image\n");
		free(img);
		return (NULL);
	}
	mlx_delete_texture(game->textures->player); // Solo si estás seguro de que ya no la necesitas.
	return (img);
}
	
t_textures	*load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (NULL);
	game->textures->wall = mlx_load_png("images/floor.png");
	game->textures->player = mlx_load_png("images/player.png");
	//game->textures->floor = mlx_load_png("images/wall.png");
	if (!game->textures->wall || !game->textures->player)
	{
		ft_fprintf(2, "Error: Failed to load one or more textures\n");
		if (game->textures->wall)
			mlx_delete_texture(game->textures->wall);
		if (game->textures->floor)
			mlx_delete_texture(game->textures->floor);
		if (game->textures->player)
			mlx_delete_texture(game->textures->player);
		free(game->textures);
		return (NULL);
	}
	return (game->textures);
}


