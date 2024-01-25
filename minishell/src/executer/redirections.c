/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:42:14 by isporras          #+#    #+#             */
/*   Updated: 2024/01/25 15:36:05 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_fork_execve(t_mini **mini)
{
	int		pid;
	t_mini	*aux;
	int		total_cmnds;
	int		i;
	int		tmpin;
	int		tmpout;

	tmpin = dup(STDIN_FILENO);
	tmpout = dup(STDOUT_FILENO);
	aux = *mini;
	if (!aux)
		return ;
	total_cmnds = aux->total_cmnds;
	i = 0;
	while (i < total_cmnds)
	{
		dup2(aux->infile, STDIN_FILENO);
		close(aux->infile);
		//if ()
		dup2(aux->outfile, STDOUT_FILENO);
		close(aux->outfile);
		pid = fork();
		if (pid == 0)
		{
			execve(aux->full_path, aux->full_cmd, NULL);
			perror("execve:");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, NULL, 0);
		i++;
	}
	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	close(tmpin);
	close(tmpout);
}

// void	ft_pipes(t_mini **mini)
// {
// 	int		fds[2];
// 	int		total_commands;
// 	int		i;
// 	t_mini	*aux;

// 	aux = *mini;
// 	if (!aux)
// 		return ;
// 	total_commands = aux->total_cmnds;
// 	if (total_commands < 2)
// 		return ;
// 	i = 0;
// 	while (i < total_commands - 1)
// 	{
// 		if (pipe(fds) == -1) {
// 			perror("pipe");
// 			exit(EXIT_FAILURE);
// 		}
// 		aux->outfile = fds[1];
// 		if (aux->next)
// 		{
// 			(aux->next)->infile = fds[0];
// 			aux = aux->next;
// 		}
// 		i++;
// 	}
// }
