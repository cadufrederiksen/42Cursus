/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:19:24 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 14:52:22 by carmarqu         ###   ########.fr       */
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
		printf("path: %s\n", tmp->full_path);
		printf("infile fd: %d\n", tmp->infile);
		printf("outfile fd: %d\n", tmp->outfile);
		tmp = tmp->next;
	}
}

void ft_print_list(t_lexer **lexer)
{
	t_lexer	*tmp;

	tmp = *lexer;
	while (tmp != NULL)
	{
		printf("word: %s\n", tmp->word);
		printf("id: %d\n", tmp->id);
		printf("type: %d\n\n", tmp->type);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_lexer	*lexer;
	t_mini	*mini;

	lexer = NULL;
	mini = NULL;
	if (argc > 1 && argv)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	while((input = readline("Minishell>")))//lee la línea
	{
		if (!ft_check_quotes(input))//checkea si hay comillas sin cerrar
			return (write(2, "quotes\n", 8), 1);
		add_history(input);
		ft_lexer(&lexer, input);
		ft_parser(&lexer, &mini, envp);
		ft_print_list(&lexer);
		ft_print_mini_lst(&mini);
		ft_free_mini_lst(&mini);
		ft_free_lexer_lst(&lexer);
		//free(input);
	}
	clear_history();
}

/* //MAIN DEBUG
 int	main(int argc, char **argv, char **envp)
 {
 	t_lexer	*lexer;
 	t_mini	*mini;
 	lexer = NULL;
 	mini = NULL;
 	char	*str = "echo \">input\"";
 	if (!argv && !argc)
 		return (1);
 	ft_lexer(&lexer, str);
 	ft_parser(&lexer, &mini, envp);
 	ft_print_list(&lexer);
 	ft_print_mini_lst(&mini);
 	return (0);
 } */