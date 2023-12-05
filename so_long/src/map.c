/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:12 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/05 12:54:13 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fill_map(char *map_name, t_data *data)
{
	int		fd;
	char	*line;
	int		x;

	x = 0;
	data->map = (char **)malloc((data->ver_len + 1) * sizeof(char *));
	if (!data->map)
		return (0);
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->map[x] = malloc(data->hor_len + 1);
		if (!data->map[x])
			return (0);
		ft_strlcpy(data->map[x], line, data->hor_len + 1);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	data->map[x] = NULL;
	return (free(line), close(fd), 1);
}

int	ft_strlen_map(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	check_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] == 'E' || line[i] == 'C' || line[i] == 'P'
		|| line[i] == '0' || line[i] == '1')
	{
		if (line[i] == 'C')
			data->col_total++;
		else if (line[i] == 'E')
			data->flag_e++;
		else if (line[i] == 'P')
		{
			data->flag_p++;
			data->y = data->ver_len;
			data->x = i;
		}
		i++;
	}
	if ((i != data->hor_len || data->flag_e > 1 || data->flag_p > 1))
		return (0);
	return (1);
}

int	format_check(char *map_name, t_data *data)
{
	int		fd;
	char	*line;

	data->ver_len = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (free(line), close(fd), 0);
	while (line)
	{
		if (data->hor_len != ft_strlen_map(line) && data->ver_len != 0)
			return (0);
		data->hor_len = ft_strlen_map(line);
		if (!check_line(line, data))
			return (free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
		data->ver_len++;
	}
	if (data->col_total == 0 || !ft_fill_map(map_name, data)
		|| data->flag_e == 0 || data->flag_p == 0)
		return (free(line), close(fd), 0);
	return (free(line), close(fd), 1);
}

int	map_check(char *name, t_data *data)
{
	if (!format_check(name, data))
		return (ft_printf("Error: Map format wrong\n"), free(data), 0);
	if (!border_check(data))
		return (ft_printf("Error: Map format wrong\n"), ft_map_free(data),
			free(data), 0);
	flood_fill(data->y, data->x, data);
	if (data->ff_c != data->col_total || data->ff_e != 1)
		return (ft_printf("Error: Unplayable map\n"), ft_map_free(data),
			free(data), 0);
	regen_map(data);
	return (1);
}
