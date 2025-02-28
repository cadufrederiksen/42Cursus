/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cupidash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:10 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/27 18:11:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long int	ft_atoi(const char *str);
int			check_param(char *str);
void		printmsg(char *str);
void		free2d(char **map, int nbr);

char	**fillmap(int nbr)
{
	char	**map;
	int		x;
	int		i;

	x = 0;
	map = (char **)malloc(sizeof(char *) * (3 * nbr + 1));
	while (x < 3 * nbr)
	{
		i = 0;
		map[x] = malloc(4 * nbr + 1);
		if (!map[x])
		{
			while (x > 0)
				free(map[--x]);
			free(map);
			return (NULL);
		}
		while (i < 4 * nbr)
			map[x][i++] = ' ';
		map[x][i] = '\0';
		x++;
	}
	map[x] = NULL;
	return (map);
}

void	set_line(int start, int end, char *line, int nbr)
{
	int	i;

	i = 0;
	while (i < (nbr * 4))
	{
		if (i >= start && i <= end)
			line[i] = '*';
		else if (line[i] != '*')
			line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}

void	draw_heart(char **map, int nbr)
{
	int	x;

	x = 0;
	while (map[x])
	{
		printmsg(map[x]);
		if (x < nbr * 3 - 2)
			write(1, "\n", 1);
		x++;
	}
}

void	set_draw(char **map, int nbr)
{
	int	x;
	int	start;
	int	end;

	start = nbr - 1;
	end = nbr;
	x = 0;
	while (x < nbr - 1)
	{
		set_line(start, end, map[x], nbr);
		set_line(((nbr * 4 - 1) - end) - 1,
			((nbr * 4 - 1) - start) - 1, map[x], nbr);
		start--;
		end++;
		x++;
	}
	start = 0;
	end = (nbr * 4) - 2;
	while (map[x])
	{
		set_line(start, end, map[x], nbr);
		start++;
		end--;
		x++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;
	int		nbr;

	if (argc < 2)
		return (printmsg("Error: No argumet given"), 1);
	if (argc > 2 || !check_param(argv[1]))
		return (printmsg("Error: Arguments are not correct"), 1);
	nbr = ft_atoi(argv[1]);
	if (nbr == 1)
	{
		printmsg(" * * \n*****\n *** \n  *  ");
		return (0);
	}
	map = fillmap(nbr);
	set_draw(map, nbr);
	draw_heart(map, nbr);
	free2d(map, nbr);
	return (0);
}
