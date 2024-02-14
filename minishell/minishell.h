/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:26:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/14 17:47:48 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <pthread.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "includes/libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/ioctl.h>

# define CMND 1
# define FLAG 2
# define STRING 3
# define FILE 4
# define GREATER 5
# define LESS 6
# define PIPE 7
# define D_GREATER 8
# define D_LESS 9
# define DELIMITER 10

typedef enum e_status
{
	INIT, //cuando no esta executando comandos
	HEREDOC, //dentro de un heredoc
	HEREDOC_END, //al salir de un heredoc
	EXIT_CMD, //caundo tiene que salir del comando
	IN_CMD,//en ejecucion
	CTRL_C,
}	t_status;


//int	g_status; variavel global

typedef struct s_envp //lista para las variables del ambiente
{
	char			*id; //PATH=
	char			*value; //value
	struct s_envp	*next;
}	t_envp;

typedef struct s_lexer
{
	char			*word; //palavra
	int				type; //Defines arriba
	int				id; //pos en la lista
	struct s_lexer	*next;//puntero al siguiente nodo
}		t_lexer;

typedef struct s_mini
{
	char			**full_cmd;//comando y sus argumentos
	char			*full_path;//camino del ejecutable si no es un builtin
	int				total_cmnds;//total de comandos
	int				id;//pos en la lista
	int				infile;//fd de entrada
	int				outfile;//fd de salida
	t_envp			**envp;
	struct s_mini	*next;//puntero al siguiente nodo
}		t_mini;

typedef struct s_exec
{
	int		pid;
	t_mini	*aux;
	int		total_cmnds;
	int		tmpin;
	int		tmpout;
	int		fdpipe[2];
}		t_exec;

extern int last_status;

//-----------------------SYSTEM--------------------------
void	ft_init_var(char **envp, t_envp **envp_list);
char	*ft_refresh_log();

//-----------------------LEXER---------------------------
char	**ft_lexer(t_lexer **lexer, char *input);
void	ft_extend_var(char **lexer);
char	**ft_split_lexer(char const *s, char c);
void	create_nodes(t_lexer **lexer, char **input);
void	ft_delete_node(t_lexer **lexer, int x);
void	ft_print_list(t_lexer **lexer);//borrar
char	**ft_get_tokens(char **lexer);
int		ft_check_quotes(char const *s);
void	ft_quotes_input(char **input);
void	ft_remove_quotes(t_lexer **lexer);
int		ft_between_quotes(char *str, int x);
char	**ft_check_syntax(char **str_lexer);
void	ft_types(t_lexer **lexer);

//-----------------------PARSER---------------------------
int		ft_parser(t_lexer **lexer, t_mini **mini, char **envp, t_envp **envp_list);
char	*ft_find_cmnd_path(char **envp, char *cmnd);
int		ft_set_path_cmnd(t_mini **mini, t_lexer **lexer, char **envp);
char	**ft_full_cmnd(t_lexer *lexer);
int		ft_set_full_cmnd(t_mini **mini, t_lexer **lexer);
t_mini	**ft_to_mini_lst(t_lexer **lexer, t_mini **mini, t_envp **envp_list);
int		ft_set_io(t_mini **mini, t_lexer **lexer);
int		ft_cmnd_error(char *error, char *boole);
int		ft_file_error(int infd, char *infile);
void	ft_perror_mod(char *error, char *mod, int exit);
void	ft_perror(char *error);
void	ft_syntax_error(char *error);
void	ft_delete_pipe(t_lexer **lexer, int pipe);

//----------------------EXECUTER---------------------------
void	ft_pipes(t_mini **mini);
int		ft_executer(t_mini **mini);
void	ft_here_doc(t_mini *mini, char *eof);

//------------------------BUILTINS---------------------------
int		ft_builtins(t_envp **envp_list, t_mini *mini);
int		ft_cd(t_mini *mini, t_envp **envp);
void	ft_echo(char **cmd, int fd);
void	ft_pwd(int fd);
void	ft_unset(t_envp **envp, char **id);
int		ft_env(int fd, t_envp **envp_list, char **cmd);
void	ft_exit(char **cmd);
char 	*find_env(t_envp **envp, char *find);
void	create_envp(t_envp **envp_list, char **envp);
void	ft_export(t_envp **envp_list, char **new_var);
void	add_new_envp(t_envp **lst, t_envp *new);
t_envp	*envp_new(char *envp);
char	*out_quotes(char *str);
void	change_env(t_envp **envp, char *find, char *new_value);
void	ft_print_envp_list(t_envp *envp);
int		ft_is_builtin(char *cmd);
int		ft_is_cd(char *cmd);

//------------------------FREE---------------------------
void	ft_free_envp_list(t_envp **envp);
void	ft_free_mini_lst(t_mini **mini);
void	free_node(t_lexer **node);
void	ft_free_lexer_lst(t_lexer **node);
void	ft_free_lsts(t_lexer **lexer, t_mini **mini, char *log);

void	ft_print_mini_lst(t_mini **mini);//borrar

//------------------------SIGNALS---------------------------
int		singal_init();

#endif