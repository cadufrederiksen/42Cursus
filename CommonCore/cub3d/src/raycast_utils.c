/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:30:57 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 19:49:24 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Place a pixel on the image
// cada píxel se define como un valor de 32 bits (RGBA)
// Los tipos como uint32_t son estándar definidos por stdint.h y 
// garantizan que el tamaño sea exactamente de 32 bits, 
// independientemente de la arquitectura
// MLX usa uint32_t para asegurarse que no se usan numeros negativos
void	put_pixel_to_image(mlx_image_t *img, int x, int y, int color)
{
	int	index;

	if (!img || !img->pixels)
	{
		ft_fprintf(2, "Error: Invalid image or pixel data\n");
		return ;
	}
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return ;
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{	//calculate the index of the array of pixels
		index = (y * (int)img->width + x) * 4;
		// Each pixel has 4 bytes (RGBA)
		img->pixels[index] = (color >> 16) & 0xFF;	// Red
		img->pixels[index + 1] = (color >> 8) & 0xFF;	// Green
		img->pixels[index + 2] = color & 0xFF;	// Blue
		img->pixels[index + 3] = 0xFF;	// Opaco
	}
}

// Clean the image
/*
Qué memoria llenar: img->pixels.
Qué valor usar: 0 (especificado como el segundo argumento).
Cuánto llenar: img->width * img->height * 4 (el tamaño total en bytes del área de píxeles).
*/
void	clear_image(mlx_image_t *img)
{
	// Llena toda la memoria de img->pixels con ceros
	ft_memset(img->pixels, 0, img->width * img->height * 4);
}
