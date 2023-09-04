/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/04 15:08:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	pid_t pid;
	int result;
	char *string;
	int i;

	i = 0;
	string = (char *)malloc(ft_strlen(argv[2]) + 1);//talvez o +1 nao precise
	while(argv[2][i] != '\0')
	{
		string[i] = argv[2][i];
		i++;
	}
	string[i] = '\0';
	ft_printf("%s\n", string);
	pid = ft_atoi(argv[1]);
	result = kill(pid, SIGUSR1);
	return (0);
}