/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:19:24 by carmarqu          #+#    #+#             */
/*   Updated: 2024/03/15 17:48:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_status;

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	ft_init_main_var(t_main *m)
{
	m->envp_list = NULL;
	m->lexer = NULL;
	m->mini = NULL;
	m->log = NULL;
	m->exit_status = 0;
}

void	ft_main_loop(t_main *m)
{
	while ((1))
	{
		m->input = readline(ft_refresh_log(m));
		if (!m->input)
			break ;
		ft_quotes_input(&m->input);
		if (ft_strncmp(m->input, "\0", 1) != 0)
			add_history(m->input);
		m->split_input = ft_split(m->input, '\n');
		m->i = 0;
		while (m->split_input[m->i])
		{
			ft_lexer(m);
			if (ft_parser(m) == 0)
				m->exit_status = ft_executer(&m->mini, m->exit_status);
			m->i++;
			ft_free_lsts(&m->lexer, &m->mini);
		}
		ft_clean_log(m);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_main	m;

	if (argc > 1 && argv)
		return (printf("Wrong number of arguments\n"), 1);
	ft_init_main_var(&m);//preciso passar char **envp para mini list
	atexit(ft_leaks);
	ft_init_var(envp, &m.envp_list);
	ft_main_loop(&m);
	final_free(m.log, m.input, &m.envp_list);
}
   