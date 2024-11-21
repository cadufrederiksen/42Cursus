/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:43:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/20 15:02:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	// Depuración para confirmar inicialización
	printf("Player structure initialized with default values.\n");
	printf("Player structure initialized with default values:\n");
	printf("pos_x: %f\n", player->pos_x);
	printf("pos_y: %f\n", player->pos_y);
	printf("dir_x: %f\n", player->dir_x);
	printf("dir_y: %f\n", player->dir_y);
	printf("plane_x: %f\n", player->plane_x);
	printf("plane_y: %f\n", player->plane_y);
}

int	init_game(t_game *game)
{
	game->mapsets = NULL;
	game->textures = NULL;
	game->pngs = NULL;
	game->mapsets = malloc(sizeof(t_mapsets));
	if (!game->mapsets)
		return (1);
	game->mapsets->vert_len = 0;
	game->mapsets->vars_flag = 0;
	/* game->textures = load_textures(game);
	if (!game->textures)
		return (ft_fprintf(2, "Error: Could not load textures\n"), 1);
	game->pngs = load_png(game);
	if (!game->pngs)
		return (ft_fprintf(2, "Error: Could not load images\n"), 1); */
	init_player(&game->player);
	return (0);
}

void	set_player_direction(t_player *player, char spawn)
{
	if (spawn == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66; //PI
		player->plane_y = 0.0;
	}
	else if (spawn == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (spawn == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
	else if (spawn == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
}

void	init_player_from_map(t_game *game)
{
	if (game->mapsets->spawn == 0)
		exit(ft_fprintf(2, "Error: Player spawn not found\n"));
	ft_printf("p_x: %d\n", game->mapsets->p_x);
	ft_printf("p_y: %d\n", game->mapsets->p_y);
	game->player.pos_x = (double)game->mapsets->p_x; // + 0.5 para centrar en la celda
	game->player.pos_y = (double)game->mapsets->p_y; // + 0.5 para centrar en la celda
	ft_printf("Calculated pos_x: %f, p_x + 0.5: %f\n", game->player.pos_x,
		game->mapsets->p_x + 0.5);
	ft_printf("Calculated pos_y: %f, p_y + 0.5: %f\n", game->player.pos_y,
		game->mapsets->p_y + 0.5);
	set_player_direction(&game->player, game->mapsets->spawn);
	game->mapsets->map[game->mapsets->p_y][game->mapsets->p_x] = '0';
}
