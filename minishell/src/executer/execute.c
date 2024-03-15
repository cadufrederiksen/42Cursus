/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:42:14 by isporras          #+#    #+#             */
/*   Updated: 2024/03/15 18:07:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_close_wait(t_exec *exec)
{
	int	status;

	waitpid(exec->pid, &status, 0);
	close(exec->aux->outfile);
	if (exec->aux->next == NULL)
		close(exec->aux->infile);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
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

void	ft_child_process(t_mini *aux, t_exec *x)
{
	dup2(aux->infile, STDIN_FILENO);
	if (aux->infile != 0)
		close(aux->infile);
	dup2(aux->outfile, STDOUT_FILENO);
	if (aux->next != NULL)
		close ((aux->next)->infile);
	if (ft_is_builtin(aux->full_cmd[0]) == 1)
		x->exit_status = ft_builtins(aux->envp, aux, x);
	else if (execve(aux->full_path, aux->full_cmd, NULL) == -1)
	{
		ft_perror_mod(aux->full_path, strerror(errno), 1);
		x->exit_status = ft_check_permission(aux->full_path);
	}
	exit(x->exit_status);
}

int	ft_exec_cases(t_exec *x)
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
			ft_child_process(x->aux, x);
		else if (x->pid < 0)
			ft_perror("fork");
		else
			x->exit_status = ft_close_wait(x);
	}
	else if (x->aux->full_cmd && ft_is_parent(x->aux->full_cmd[0]) != 0
		&& x->aux->broken == 0)
		x->exit_status = ft_bt_parent(x->aux, x->aux->envp, x);
	else if (x->aux->broken == 1)
		close(x->aux->outfile);
	return (x->exit_status);
}

int	ft_executer(t_mini **mini, int e_sts)
{
	t_exec	*exec;
	int		exit_status;

	if (ft_init_data_exec(mini, &exec) > 0)
		return (1);
	g_status = IN_CMD;
	exec->exit_status = e_sts;
	if (exec->total_cmnds == 1 && ft_is_builtin(exec->aux->full_cmd[0])
		&& exec->aux->broken == 0)
		exec->exit_status = ft_builtins(exec->aux->envp, exec->aux, exec);
	else
	{
		while (exec->aux && exec->i < exec->total_cmnds)
		{
			exec->exit_status = ft_exec_cases(exec);
			exec->i++;
			exec->aux = exec->aux->next;
		}
	}
	ft_close_restore(exec);
	exit_status = exec->exit_status;
	free(exec);
	return (exit_status);
}
