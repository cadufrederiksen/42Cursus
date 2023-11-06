/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:58:06 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/06 10:12:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int border_check(t_data *data)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if(data->map[x][i] != '1')
		return(0);
	while (i < data->hor_len - 1 && data->map[x][i] == '1')
		i++;
	while(x < data->ver_len - 1 && data->map[x][i] == '1')
		x++;
	while(i > 0 && data->map[x][i] == '1')
		i--;
	while(x > 0 && data->map[x][i] == '1')
		x--;
	if(x != 0 || i != 0)
		return(0);
	return(1);
}