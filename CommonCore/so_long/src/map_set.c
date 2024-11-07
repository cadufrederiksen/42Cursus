/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:58:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/07 12:45:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	border_check(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (data->map[x][i] != '1')
		return (0);
	while (i < data->hor_len - 1 && data->map[x][i] == '1')
		i++;
	while (x < data->ver_len - 1 && data->map[x][i] == '1')
		x++;
	while (i > 0 && data->map[x][i] == '1')
		i--;
	while (x > 0 && data->map[x][i] == '1')
		x--;
	if (x != 0 || i != 0)
		return (0);
	return (1);
}

void	flood_fill(int y, int x, t_data *data)
{
	printf("%d %d\n", y, x);
	printf("%d %d\n", data->ver_len, data->hor_len);
	printf("%d %d\n", data->y, data->x);
	if (data->map[y][x] == '1' || data->map[y][x] == 'x'
		|| data->map[y][x] == 'c' || data->map[y][x] == 'e')
		return ;
	if (data->map[y][x] == 'C')
	{
		data->ff_c++;
		data->map[y][x] = 'c';
	}
	if (data->map[y][x] == 'E')
	{
		data->map[y][x] = 'e';
		data->ff_e++;
	}
	if (data->map[y][x] == '0')
		data->map[y][x] = 'x';
	flood_fill(y, x - 1, data);
	flood_fill(y - 1, x, data);
	flood_fill(y + 1, x, data);
	flood_fill(y, x + 1, data);
}

void	regen_map(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (i < data->hor_len)
	{
		x = 0;
		while (x < data->ver_len)
		{
			if (data->map[x][i] == 'e')
				data->map[x][i] = 'E';
			if (data->map[x][i] == 'x')
				data->map[x][i] = '0';
			if (data->map[x][i] == 'c')
				data->map[x][i] = 'C';
			x++;
		}
		i++;
	}
}
