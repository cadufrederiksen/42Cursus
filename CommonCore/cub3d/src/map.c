/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/15 13:57:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	flood_fill(int y, int x, t_game *game)
{

	if (game->mapsets->map[y][x] == '1' || game->mapsets->map[y][x] == 'x'
		|| game->mapsets->map[y][x] == 'c' || game->mapsets->map[y][x] == 'e')
		return ;
	if (game->mapsets->map[y][x] == '0')
		game->mapsets->map[y][x] = 'x';
	flood_fill(y, x - 1, game);
	flood_fill(y - 1, x, game);
	flood_fill(y + 1, x, game);
	flood_fill(y, x + 1, game);
} */

int		is_map(char *line)//buscar manera de checkear si hay los 6 elementos
{
	if (line[0] == '\n')
		return (0);
	if (!ft_strncmp(line, "NO", 3))
		return (0);
	else if (!ft_strncmp(line, "SO", 3))
		return (0);
	else if (!ft_strncmp(line, "WE", 3))
		return (0);
	else if (!ft_strncmp(line, "EA", 3))
		return (0);
	else if (!ft_strncmp(line, "F", 2))
		return (0);
	else if (!ft_strncmp(line, "C", 2)) 
		return (0);
	else 
		return(1);
}

int		get_map(char *file_name, t_game* game)
{
	char	*line;
	int		fd;
	int		x;

	x = 0;
	game->mapsets->map = (char **)malloc(sizeof(char *) * (game->mapsets->vert_len + 1));
	if(!game->mapsets->map)
		return (0);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);	
	while (line) //mira linea por linea para obtener las infos
	{
		if (is_map(line))
		{
			game->mapsets->map[x] = ft_substr(line, 0, ft_strlen_map(line));
			x++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->mapsets->map[x] = NULL;
	return (close(fd), free(line), 0);
}
