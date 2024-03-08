/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:26:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/03/08 17:41:23 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "includes/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
	INIT,
	HEREDOC,
	HEREDOC_END,
	EXIT_CMD,
	IN_CMD,
	CTRL_C,
}	t_status;

typedef struct s_token
{
	char	**lx;
	char	*tk;
	int		i;
	int		j;
	int		d;
}	t_token;

typedef struct s_envp
{
	char			*id;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_lexer
{
	char			*word;
	int				type;
	int				id;
	int				broken;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_mini
{
	char			**full_cmd;
	char			*full_path;
	int				total_cmnds;
	int				id;
	int				infile;
	int				outfile;
	int				broken;
	t_envp			**envp;
	struct s_mini	*next;
}	t_mini;

typedef struct s_main
{
	char	*log;
	char	*input;
	t_lexer	*lexer;
	t_mini	*mini;
	t_envp	*envp_list;
	char	**split_input;
	int		i;
	int		exit_status;
}	t_main;

typedef struct s_exec
{
	int		pid;
	t_mini	*aux;
	int		total_cmnds;
	int		tmpin;
	int		tmpout;
	int		fdpipe[2];
	int		i;
	int		exit_status;
}	t_exec;

extern int	g_status;

void		ft_init_var(char **envp, t_envp **envp_list);
char		*ft_refresh_log(t_main *main);
void		ft_lexer(t_main *m);
void		ft_extend_var(char **lexer, t_main *m);
char		**ft_split_lexer(char const *s, char c);
void		create_nodes(t_lexer **lexer, char **input);
t_lexer		*ft_delete_node(t_lexer **lexer, int x);
char		**ft_get_tokens(char **lexer);
char		**ft_add_token(t_token *t);
int			ft_check_quotes(char const *s);
void		ft_quotes_input(char **input);
void		ft_remove_quotes(t_lexer **lexer);
int			ft_between_quotes(char *str, int x);
char		**ft_check_syntax(char **str_lexer);
char		*ft_check_end_pipe(char *input);
void		ft_types(t_lexer **lexer);
int			ft_parser(t_main *m);
char		*ft_find_cmnd_path(t_envp **envp, char *cmnd);
void		ft_set_path(t_mini **mi, t_lexer **lx, t_envp **en, t_main *m);
char		**ft_full_cmnd(t_lexer *lexer);
int			ft_set_full_cmnd(t_mini **mini, t_lexer **lexer);
t_mini		**ft_to_mini_lst(t_lexer **lexer, t_mini **mini,
				t_envp **envp_list);
int			ft_set_io(t_mini **mini, t_lexer **lexer);
int			ft_cmnd_error(char *error, char *boole);
int			ft_file_error(int infd, char *infile);
int			ft_perror_mod(char *error, char *mod, int exit);
void		ft_perror(char *error);
void		ft_syntax_error(char *error);
t_lexer		*ft_delete_pipe(t_lexer **lexer, int pipe);
void		ft_check_bad_input(t_lexer **lexer, t_main *m);
int			ft_check_permission(char *path);
int			ft_check_is_dir(char *path);
void		ft_pipes(t_mini **mini);
int			ft_executer(t_mini **mini, int e_sts);
void		ft_here_doc(t_mini *mini, char *eof);
int			ft_bt_parent(t_mini *mini, t_envp **envp, t_exec *x);
int			ft_is_parent(char *cmd);
void		ft_close_restore(t_exec *exec);
int			ft_init_data_exec(t_mini **mini, t_exec **exec);
int			ft_builtins(t_envp **envp_list, t_mini *mini, t_exec *x);
int			ft_cd(t_mini *mini, t_envp **envp);
void		ft_echo(char **cmd, int fd);
void		ft_pwd(int fd);
void		ft_unset(t_envp **envp, char **id);
int			ft_env(int fd, t_envp **envp_list, char **cmd);
void		ft_exit(char **cmd, int exit_sts);
char		*find_env(t_envp **envp, char *find);
void		create_envp(t_envp **envp_list, char **envp);
int			ft_export(t_envp **envp_list, char **new_var, t_exec *exec);
void		add_new_envp(t_envp **lst, t_envp *new);
t_envp		*envp_new(char *envp);
char		*out_quotes(char *str);
void		change_env(t_envp **envp, char *find, char *new_value);
int			ft_is_builtin(char *cmd);
int			ft_is_cd(char *cmd);
void		ft_free_envp_list(t_envp **envp);
void		ft_free_mini_lst(t_mini **mini);
void		free_node(t_lexer **node);
void		ft_free_lexer_lst(t_lexer **node);
void		ft_free_lsts(t_lexer **lexer, t_mini **mini);
void		final_free(char *log, char *input, t_envp **envp);
void		ft_clean_log(t_main *m);
int			singal_init(void);
void		ft_init_main_var(t_main *m);
void		ft_print_mini_lst(t_mini **mini); //borrar
void		ft_print_list(t_lexer **lexer);//borrar
void		ft_print_envp_list(t_envp **envp);

#endif