/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/21 17:59:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define IMG 64
# define ROTATION_SPEED 0.05
# define FOV 60 // FOV del player
# define TILE_SIZE 30 //tamaño del bloque

typedef struct s_mapsets
{
	char	spawn; // flags para verificar
	int		p_x;   // hor
	int		p_y;   // vert
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char 	*f_path; // rgb como str
	char	*c_path;
	char	**map;
	int		ceiling_rgb[3];
	int		floor_rgb[3];
	int		vert_len;
	int		hor_len;
	int 	vars_flag; // checkea si hay 6 innstrucciones
}				t_mapsets;

// flood fill
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	int		pos_x;		// Posición del jugador
	int		pos_y;		// Posición del jugador
	double	angle;
}				t_player;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x; 	// deltadist: Distancia que el rayo necesita para recorrer un bloque de mapa en los ejes X e Y
	double		deltadist_y;
	double		sidedist_x; 	// sidedist: Distancia desde la posición actual del rayo hasta la próxima intersección con una línea de la cuadrícula
	double		sidedist_y;
	double		perp_walldist; 	// Distancia perpendicular desde el jugador hasta la pared que el rayo golpea
	int			map_x; 			// map_: Coordenadas del bloque del mapa
	int			map_y;
	int			step_x;
	int			step_y;
	int			side; 			// Indica si el rayo golpeó una pared vertical (0) u horizontal (1)
	int			line_height; 	// Altura de la línea a dibujar en pantalla para esta columna
	int			draw_start; 	// draw_: Puntos en la pantalla donde empieza y termina la línea que representa la pared
	int			draw_end;
}				t_ray;

/* no hace falta, estuve mirando y me parece que las texturas son pintadas pixel a pixel, no con una imagen directamente
typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
}					t_textures;

 typedef	struct s_img
{
	mlx_image_t *player;
} t_img;
 */
typedef struct s_game
{
	mlx_t		*mlx;		// Todas las funciones de MLX42 trabajan con punteros (mlx_image_t *), por lo que se necesita que img sea un puntero para pasarla correctamente a esas funciones
	mlx_image_t	*img;		// Imagen donde dibujar cada frame antes de actualizar la ventana
	t_img		*pngs;
	t_mapsets	*mapsets;
	t_player	player; 	// Estructura para manejar la posición y orientación del jugador
	t_ray		ray; 		// Estructura para almacenar datos relacionados con el raycasting
	t_textures	*textures; 	// Almacena las texturas necesarias para renderizar los elementos
}				t_game;

//key hooks
void	moves(mlx_key_data_t keydata, void *param);

//parser
int				ft_strlen_map(const char *s);
int				get_map(char *file_name, t_game *game);
int				check_input(char *file_name, t_game *game);
void			free_game(t_game *game);
char			*cut_line(char *line, t_game *game);
void			free2d(char **str);

// init structures
int				init_game(t_game *game);
void			init_player(t_player *player);
void			set_player_direction(t_player *player, char spawn);
void			init_player_from_map(t_game *game);

// loading png
t_textures		*load_textures(t_game *game);
t_img			*load_png(t_game *game);

// calculations
void			calculate_ray_direction(t_game *game, int x);
void			calculate_delta_dist(t_game *game);
void			calculate_perp_wall_dist(t_game *game);
void			calculate_draw_limits(t_game *game);

// raycasting
void			put_pixel_to_image(mlx_image_t *img, int x, int y, int color);
void			clear_image(mlx_image_t *img);
void			initialize_step_and_side_dist(t_game *game);
void			perform_dda(t_game *game);
void			draw_column(t_game *game, int x);
void			cast_ray(t_game *game, int x);
void			draw_frame(t_game *game);

#endif