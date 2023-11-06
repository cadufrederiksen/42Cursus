/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/06 16:17:38 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef	struct s_texture
{
	mlx_texture_t *main;
	mlx_texture_t *colec;
	mlx_texture_t *floor;
	mlx_texture_t *exit;
	mlx_texture_t *wall;
} t_texture;

typedef struct s_image
{
	mlx_image_t *main;
	mlx_image_t *colec;
	mlx_image_t *floor;
	mlx_image_t *exit;
	mlx_image_t *wall;
} t_image;


typedef struct s_data
{
	struct s_texture *text;
	struct s_image *img;
	mlx_t *mlx_ptr;
	char **map;
	int ver_len;//quantidade de colunas () y
	int hor_len;//quantidade de fileiras x
	int col_total; //quantidade de coletáveis
	int flag_e;
	int flag_p;
	int x;
	int y; //x e y são as posições inicias do personagem ("P")
	

} t_data;


int		map_check(char *map_name, t_data *data);
int		border_check(t_data *data);
int		create_text(t_data *data);
void	moves(mlx_key_data_t keydata, void *param);
#endif