/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:46:14 by isporras          #+#    #+#             */
/*   Updated: 2024/02/19 18:11:40 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int last_status;

//MAIN DEBUG
 int	main(int argc, char **argv, char **envp)
 {
 	t_lexer	*lexer;
 	t_mini	*mini;
 	t_envp	*envp_list;

 	envp_list = NULL;
 	lexer = NULL;
 	mini = NULL;
 	last_status = 0;
 	char	*input = ft_strdup("echo <\"minishell_tester/test_files/infile\" <mis <\"minishell_tester/test_files/infile\"");
 	if (!argv && !argc)
 		return (1);
 	ft_init_var(envp, &envp_list);
 	ft_quotes_input(&input);
	ft_lexer(&lexer, input);
	if (ft_parser(&lexer, &mini, &envp_list) == -1)
	{
		ft_print_list(&lexer);
		ft_executer(&mini);
	}
	//ft_print_mini_lst(&mini);
	ft_free_lsts(&lexer, &mini);
 	//ft_print_mini_lst(&mini);
 	//ft_free_lsts(&lexer, &mini);
	printf("last status end: %d\n", last_status);
 	return (0);
 }
//cat ./test_files/infile_big | grep oi