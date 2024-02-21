/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:42:14 by isporras          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_close_wait(t_exec *exec)
{
	int	status;

	waitpid(exec->pid, &status, 0);
	close(exec->aux->outfile);
	if (exec->aux->next == NULL)
		close(exec->aux->infile);
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else
		g_status = 1;
}

void	ft_set_next_pipe(t_exec *exec)
{
	if (exec->total_cmnds > 1)
	{
		pipe(exec->fdpipe);
		if (exec->aux->next && (exec->aux->next)->infile == STDIN_FILENO)
			(exec->aux->next)->infile = exec->fdpipe[0];
		else if (exec->aux->next && (exec->aux->next)->infile != STDIN_FILENO)
			close(exec->fdpipe[0]);
		if (exec->aux->outfile == STDOUT_FILENO)
			exec->aux->outfile = exec->fdpipe[1];
		else if (exec->aux->outfile != STDOUT_FILENO)
			close(exec->fdpipe[1]);
	}
}

void	ft_child_process(t_mini *aux)
{
	dup2(aux->infile, STDIN_FILENO);
	if (aux->infile != 0)
		close(aux->infile);
	dup2(aux->outfile, STDOUT_FILENO);
	if (aux->next != NULL)
		close ((aux->next)->infile);
	if (ft_is_builtin(aux->full_cmd[0]) == 1)
		ft_builtins(aux->envp, aux);
	else if (execve(aux->full_path, aux->full_cmd, NULL) == -1)
	{
		ft_perror_mod(aux->full_path, strerror(errno), 1);
		ft_check_permission(aux->full_path);
	}
	exit(g_status);
}

void	ft_exec_cases(t_exec *x)
{
	if (x->total_cmnds > 1 && x->i < x->total_cmnds - 1)
		ft_set_next_pipe(x);
	if (((x->aux->broken == 0 && x->aux->next && x->aux->next->broken == 0)
			|| (!x->aux->next && x->aux->broken == 0))
		&& ((x->aux->full_cmd && ft_is_parent(x->aux->full_cmd[0]) == 0
				&& ft_is_builtin(x->aux->full_cmd[0]) == 1)
			|| (x->aux->full_path && ft_is_builtin(x->aux->full_cmd[0]) == 0)))
	{
		x->pid = fork();
		if (x->pid == 0)
			ft_child_process(x->aux);
		else if (x->pid < 0)
			ft_perror("fork");
		else
			ft_close_wait(x);
	}
	else if (x->aux->full_cmd && ft_is_parent(x->aux->full_cmd[0]) != 0
		&& x->aux->broken == 0)
		ft_bt_parent(x->aux, x->aux->envp);
	else if (x->aux->broken == 1)
		close(x->aux->outfile);
}

int	ft_executer(t_mini **mini)
{
	t_exec	*exec;

	if (ft_init_data_exec(mini, &exec) > 0)
		return (g_status);
	if (exec->total_cmnds == 1 && ft_is_builtin(exec->aux->full_cmd[0])
		&& exec->aux->broken == 0)
		ft_builtins(exec->aux->envp, exec->aux);
	else
	{
		while (exec->aux && exec->i < exec->total_cmnds)
		{
			ft_exec_cases(exec);
			exec->i++;
			exec->aux = exec->aux->next;
		}
	}
	ft_close_restore(exec);
	free(exec);
	return (g_status);
}
