/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:42:14 by isporras          #+#    #+#             */
/*   Updated: 2024/01/24 12:14:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_fork_execve(t_mini *mini)
{
	int fork;

	fork = fork();
	if(fork == 0)
	{
		execvp(mini->full_cmd[i][0], mini->full_cmd[i][1]);
		perror("execvp:");
		exit(1);
	}
}

void	ft_redirections(t_mini **mini)
{
	//guardar in/out
	t_redir	redir;
	int	i;

	redir.tmpin = dup(0);
	redir.tmpout = dup(1);
	i = 0;
	while (i < numsimplecommands)
	{
		dup2(mini->infile, 0);//redirijir input
		close(redir.fdin);
		if (i == numsimplecommands1) // Último comando
		{
			if(outfile)
				redir.fdout = open(mini->outfile);
			else
				redir.fdout = dup(redir.tmpout);
		}
		else //Demás comandos
		{
			pipe(redir.fdpipe);
			redir.fdout = redir.fdpipe[1];
			redir.fdin = redir.fdpipe[0];
		}
		dup2(redir.fdout, 1);// Redirijir output
		close(redir.fdout);
		redir.fork = fork();// Crear proceso hijo
		if(redir.fork == 0)
		{
			execvp(mini->full_cmd[i][0], mini->full_cmd[i][1]);
			perror("execvp:");
			exit(1);
		}
		i++;
	}
	dup2(redir.tmpin, 0);//Restaurar in/out
	dup2(redir.tmpout, 1);
	close(redir.tmpin);
	close(redir.tmpout);
	if (!background)// Esperar al último comando
		waitpid(redir.fork, NULL)
}
