/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:59 by carmarqu          #+#    #+#             */
/*   Updated: 2023/10/23 16:23:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

void key_press(mlx_key_data_t keycode, void *param)
{
	param = 0;
	if (keycode.key)
		ft_printf("Ok");
}

int	main(void)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init(1980, 1080, "so_long", NULL);
	mlx_key_hook(data->mlx_ptr, &key_press, NULL);
	mlx_loop(data->mlx_ptr);
	
}   