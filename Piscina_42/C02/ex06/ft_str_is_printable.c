/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:51:29 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/22 10:53:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= ' ' && str[i] <= '~') || str[i] == '\0')
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
