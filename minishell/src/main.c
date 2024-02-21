/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:19:24 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/21 16:31:56 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_status;

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	ft_print_mini_lst(t_mini **mini)
{
	t_mini	*tmp;

	tmp = *mini;
	while (tmp != NULL)
	{
		printf("cmd:\n");
		ft_print_split(tmp->full_cmd);
		printf("total cmds: %d\n", tmp->total_cmnds);
		printf("id: %d\n", tmp->id);
		printf("path: %s\n", tmp->full_path);
		printf("infile fd: %d\n", tmp->infile);
		printf("outfile fd: %d\n\n", tmp->outfile);
		tmp = tmp->next;
	}
}

void	ft_print_list(t_lexer **lexer)
{
	t_lexer	*tmp;

	tmp = *lexer;
	printf("LISTA:\n");
	while (tmp)
	{
		printf("word: %s\n", tmp->word);
		printf("id: %d\n", tmp->id);
		printf("type: %d\n", tmp->type);
		printf("broken: %d\n\n", tmp->broken);
		tmp = tmp->next;
	}
}

void	ft_init_main_var(t_main *m)
{
	m->envp_list = NULL;
	m->lexer = NULL;
	m->mini = NULL;
	m->log = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_main	m;

	ft_init_main_var(&m);
	g_status = 0;
	if (argc > 1 && argv)
		return (printf("Wrong number of arguments\n"), 1);
	ft_init_var(envp, &m.envp_list);
	//atexit(ft_leaks);
	while ((1))
	{
		m.input = readline(ft_refresh_log(&m));
		if (!m.input)
			break ;
		ft_quotes_input(&m.input);
		if (ft_strncmp(m.input, "\0", 1) != 0)
			add_history(m.input);
		m.split_input = ft_split(m.input, '\n');
		m.i = 0;
		while (m.split_input[m.i])//Maneja que haya saltos de línea en el input
		{
			ft_lexer(&m.lexer, m.split_input[m.i], &m.envp_list);
			if (ft_parser(&m.lexer, &m.mini, &m.envp_list) == 0)
				g_status = ft_executer(&m.mini);	
			//ft_print_list(&m.lexer);
			//ft_print_mini_lst(&m.mini);
			ft_free_lsts(&m.lexer, &m.mini);
			m.i++;
		}
		ft_clean_log(m.log, m.input, m.split_input);
	}
	final_free(m.log, m.input, &m.envp_list);
}
