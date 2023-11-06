/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:12:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/06 10:59:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int create_text(t_data *data)
{
	data->text = malloc(sizeof(t_texture));
	if (!data->text)
		return (0);
	data->text->onça = mlx_load_png("../so_long/png/onça.png");
	if (!data->text->onça)
		return (0);
	data->img = malloc(sizeof(t_image));
	if (data->img)
		return(0);
	data->img->onça = mlx_texture_to_image(data->mlx_ptr, data->text->onça);
	if (data->img->onça)
		return(0);
	mlx_delete_texture(data->text->onça);
	mlx_image_to_window(data->mlx_ptr, data->img->onça, 890, 540);
	return (1);
}