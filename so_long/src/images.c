/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:12:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/09 13:29:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int put_img(t_data *data, char c, int x, int i)//c é o caracter do mapa e y e x a posição
{
	if (c == '1')
		mlx_image_to_window(data->mlx_ptr, data->img->wall, x * 32, i * 32);
	if (c == '0')
		mlx_image_to_window(data->mlx_ptr, data->img->floor, x * 32, i * 32);
	if (c == 'C')
		mlx_image_to_window(data->mlx_ptr, data->img->colec, x * 32, i * 32);
	if (c == 'E')
		mlx_image_to_window(data->mlx_ptr, data->img->exit, x * 32, i * 32);
	if (c == 'P')
		mlx_image_to_window(data->mlx_ptr, data->img->main_r, x * 32, i * 32);
	return(1);
}

int img_to_win(t_data *data)
{
	int i;
	int x;

	x = 0;
	while (x < data->hor_len)
	{
		i = 0;
		while (i < data->ver_len)
		{
			put_img(data, data->map[i][x], x, i);
			i++;
		}
		x++;
	}
	return (1);
}

int create_img(t_data *data)
{
	data->img = malloc(sizeof(t_image));
	if (!data->img)
		return(0);
	data->img->main_l = mlx_texture_to_image(data->mlx_ptr, data->text->main_l);
	data->img->main_r = mlx_texture_to_image(data->mlx_ptr, data->text->main_r);
	data->img->colec = mlx_texture_to_image(data->mlx_ptr, data->text->colec);
	data->img->floor = mlx_texture_to_image(data->mlx_ptr, data->text->floor);
	data->img->exit = mlx_texture_to_image(data->mlx_ptr, data->text->exit);
	data->img->wall = mlx_texture_to_image(data->mlx_ptr, data->text->wall);
	mlx_delete_texture(data->text->main_l);
	mlx_delete_texture(data->text->main_r);
	mlx_delete_texture(data->text->colec);
	mlx_delete_texture(data->text->floor);
	mlx_delete_texture(data->text->exit);
	mlx_delete_texture(data->text->wall);
 	if(!img_to_win(data))
		return(0); 
	return (1);
}

int create_text(t_data *data)//a imagem ainda ta muito grande 
{
	data->text = malloc(sizeof(t_texture));
	if (!data->text)
		return (0);
	data->text->main_r = mlx_load_png("../so_long/png/onça_dir_32.png");
	if (!data->text->main_r)
		return (0);
	data->text->main_l = mlx_load_png("../so_long/png/onça_esq_32.png");
	if (!data->text->main_l)
		return (0);
	data->text->colec = mlx_load_png("../so_long/png/bife_32.png");
	if (!data->text->colec)
		return (0);
	data->text->floor = mlx_load_png("../so_long/png/mato_32.png");
	if (!data->text->floor)
		return (0);
	data->text->exit = mlx_load_png("../so_long/png/emato_32.png");
	if (!data->text->exit)
		return (0);
	data->text->wall = mlx_load_png("../so_long/png/rio_32.png");
	if (!data->text->wall)
		return (0);
	if (!create_img(data))	
		return(0);
	return (1);
}