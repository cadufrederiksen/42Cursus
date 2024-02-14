/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:46:14 by isporras          #+#    #+#             */
/*   Updated: 2024/02/13 12:41:44 by carmarqu         ###   ########.fr       */
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
	while (tmp)
	{
		printf("word: %s\n", tmp->word);
		printf("id: %d\n", tmp->id);
		printf("type: %d\n\n", tmp->type);
		tmp = tmp->next;
	}
}

void	final_free(char *input, char *log, t_envp **envp)
{
	ft_free_envp_list(envp);//hay que quedar fuera del bucle
	free(log);
	free(input);
}

int last_status;

//MAIN DEBUG
 int	main(int argc, char **argv, char **envp)
 {
 	t_lexer	*lexer;
 	t_mini	*mini;
 	t_envp	*envp_list;
 	int		last_status;

 	envp_list = NULL;
 	lexer = NULL;
 	mini = NULL;
 	last_status = 0;
 	char	*input = ft_strdup("ech <123 <infile hi >outfile1| >outfile");
 	if (!argv && !argc)
 		return (1);
 	ft_init_var(envp, &envp_list);
 	ft_quotes_input(&input);
 	if (ft_lexer(&lexer, input) != NULL)//crea la lista de tokens
 	{
 		if (ft_parser(&lexer, &mini, envp, &envp_list) == -1)
				last_status = ft_executer(&mini);
 		//ft_print_list(&lexer);
		//ft_print_mini_lst(&mini);
 	}
 	//ft_print_mini_lst(&mini);
	printf("last status: %d\n", last_status);
 	//ft_free_lsts(&lexer, &mini);
 	return (0);
 }
//cat ./test_files/infile_big | grep oi