/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/27 21:37:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char **argv, int argc)
{
	int		j;
	int		i;
	char	c;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			c = argv[j][i];
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		if (s1[i] == s2[i])
			j = s1[i] - s2[i];
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		j = s1[i] - s2[i];
	return (j);
}

char	**ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	j = 1;
	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[j], argv[i]) > 0)
			{
				c = argv[i];
				argv[i] = argv[j];
				argv[j] = c;
				i++;
			}
			else
				i++;
		}
		j++;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		ft_putchar(argv, argc);
	}
	return (0);
}
