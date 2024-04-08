/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:02:57 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/15 10:38:05 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_var(t_data *data)
{
	data->ver_len = 0;
	data->hor_len = 0;
	data->col_total = 0;
	data->flag_e = 0;
	data->flag_p = 0;
	data->ff_c = 0;
	data->ff_e = 0;
}

void	resize_ptr(int32_t width, int32_t height, void *param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

int	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init(data->hor_len * 32, data->ver_len * 32,
			"so_long_bonus", 1);
	mlx_resize_hook(data->mlx_ptr, &resize_ptr, data);
	mlx_key_hook(data->mlx_ptr, &moves, data);
	if (!create_text(data))
		return (0);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
	return (1);
}

void	ft_map_free(t_data *data)
{
	while (data->ver_len-- > 0)
	{
		if (data->map[data->ver_len])
			free(data->map[data->ver_len]);
	}
	free(data->map);
}
