/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:46:14 by isporras          #+#    #+#             */
/*   Updated: 2024/03/14 10:49:20 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_envp_list(t_envp *envp)//borrar despues
{
	t_envp	*tmp;

	tmp = envp;
	printf("ENV LIST:\n");
	while (tmp != NULL)
	{
		printf("%s", tmp->id);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
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

int g_status;

//MAIN DEBUG
 int	main(int argc, char **argv, char **envp)
 {
 	t_main	m;

	ft_init_main_var(&m);
 	ft_init_var(envp, &m.envp_list);
 	m.input = ft_strdup("echo ");
 	if (!argv && !argc)
 		return (1);
 	ft_quotes_input(&m.input);
	ft_lexer(&m);
	if (ft_parser(&m) == 0)
	{
		m.exit_status = ft_executer(&m.mini, m.exit_status);
	}
	//ft_print_mini_lst(&mini);
	ft_free_lsts(&m.lexer, &m.mini);
 	//ft_print_mini_lst(&mini);
 	//ft_free_lsts(&lexer, &mini);
	printf("last status end: %d\n", g_status);
 	return (0);
 }
//cat ./test_files/infile_big | grep oi