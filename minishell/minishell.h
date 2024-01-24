/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:26:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 15:10:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "includes/libft/libft.h"
# include <errno.h>

# define CMND 1
# define FLAG 2
# define STRING 3
# define FILE 4
# define GREATER 5
# define LESS 6
# define PIPE 7
# define D_GREATER 8
# define D_LESS 9

//int	g_status; variavel global

typedef struct s_lexer
{
	char *word; //palavra
	//int tokens; //cantidad de tokens
	//char **args; //args
	int type; //1-> func, 2->flags, 3->string, 4->files 5->token
	int id; //pos en la lista
	struct s_lexer *next;//puntero al siguiente nodo

}		t_lexer;

typedef struct s_mini
{
	char			**full_cmd;//comando y sus argumentos
	char			*full_path;//camino del ejecutable si no es un builtin
	int				cmd_laps;
	int				cmd_id;
	int				infile;//fd de entrada
	int				outfile;//fd de salida
	struct s_mini	*next;//puntero al siguiente nodo
}		t_mini;

typedef struct s_redir
{
	int	tmpin;
	int	tmpout;
	int	fork;
	int	fdin;
	int	fdout;
	int	fdpipe[2];
}		t_redir;

char		**ft_lexer(t_lexer **lexer, char *input);
void		ft_extend_var(char **lexer);
char		**ft_split_lexer(char const *s, char c);
void		create_nodes(t_lexer **lexer, char **input);
void		ft_print_list(t_lexer **lexer);
void		free_node(t_lexer **node);
void		ft_types(t_lexer **lexer);
char		**ft_get_tokens(char **lexer);
char const	*ft_check_quotes(char const *s);
t_mini		**ft_parser(t_lexer **lexer, t_mini **mini, char **envp);
char		*ft_find_cmnd_path(char **envp, char *cmnd);
char		**ft_full_cmnd(t_lexer *lexer);
t_mini		**ft_to_mini_lst(t_lexer **lexer, t_mini **mini, char **envp);
void		ft_free_mini_lst(t_mini **mini);
void		ft_free_lexer_lst(t_lexer **node);
void		ft_error(char *error, char *boole, int errint);
void		ft_set_io(t_mini *m_node, t_lexer **lexer, int lap);

#endif