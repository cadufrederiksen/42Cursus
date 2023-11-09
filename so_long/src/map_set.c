/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:58:06 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/09 14:10:32 by carmarqu         ###   ########.fr       */
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

void	flood_fill(int x, int y, t_data *data)
{
	if (data->map[x][y] == '1' || data->map[x][y] == 'x'
		|| data->map[x][y] == 'c' || data->map[x][y] == 'e')
		return ;
	if (data->map[x][y] == 'C')
	{
		data->ff_c++;
		data->map[x][y] = 'c';
	}
	if (data->map[x][y] == 'E')
	{
		data->map[x][y] = 'e';
		data->ff_e++;
	}
	if (data->map[x][y] == '0')
		data->map[x][y] = 'x';
	flood_fill(x, y - 1, data);
	flood_fill(x - 1, y, data);
	flood_fill(x + 1, y, data);
	flood_fill(x, y + 1, data);
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
