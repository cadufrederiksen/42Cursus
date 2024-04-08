 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/14 15:15:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_texture
{
	mlx_texture_t		*main_l;
	mlx_texture_t		*main_r;
	mlx_texture_t		*colec;
	mlx_texture_t		*floor;
	mlx_texture_t		*exit;
	mlx_texture_t		*wall;
}						t_texture;

typedef struct s_image
{
	mlx_image_t			*main_l;
	mlx_image_t			*main_r;
	mlx_image_t			*colec;
	mlx_image_t			*floor;
	mlx_image_t			*exit;
	mlx_image_t			*wall;
}						t_image;

typedef struct s_data
{
	struct s_texture	*text;
	struct s_image		*img;
	mlx_t				*mlx_ptr;
	char				**map;
	int					ver_len;//quantidade de colunas () y
	int					hor_len;//quantidade de fileiras y
	int					col_total;//quantidade de coletáveis
	int					flag_e;//total de e's
	int					flag_p;//total de p's
	int					x;
	int					y;//x e y são as posições inicias do personagem ("P")
	int					ff_c;//contador de c's de flood_fill
	int					ff_e;//contador de e's de flood fill
	int					total_moves;

}						t_data;

int						main(int argc, char **argv);
int						init_game(t_data *data);
int						map_check(char *map_name, t_data *data);
int						border_check(t_data *data);
int						create_text(t_data *data);
void					moves(mlx_key_data_t keydata, void *param);
void					flood_fill(int y, int x, t_data *data);
void					regen_map(t_data *data);
void					init_var(t_data *data);
void					ft_map_free(t_data *data);
void					move_up2(t_data *data);
void					move_down2(t_data *data);
void					move_left2(t_data *data);
void					move_right2(t_data *data);

#endif