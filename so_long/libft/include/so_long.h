/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/10/24 15:34:19 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "ft_printf.h"

typedef struct s_data
{
	mlx_t *mlx_ptr;
	char **map;
	int ver_len;//quantidade de colunas () y
	int hor_len;//quantidade de fileiras x
	int col_total; //quantidade de coletáveis
	int flag_e;
	int flag_p;

} t_data;


int		map_check(char *map_name, t_data *data);
int		border_check(t_data *data);

#endif