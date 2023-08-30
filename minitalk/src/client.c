/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/30 13:20:55 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	kill((pid_t)argv[1], SIGUSR1);
	return(0);
}