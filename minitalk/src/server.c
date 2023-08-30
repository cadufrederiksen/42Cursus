/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/30 13:19:48 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

int main(void)
{
	int pid;
	
	pid = getpid();
	ft_printf("%d\n", pid);
	pause();
	ft_printf("%s\n", "voltei");
	return(0);
}