/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:49 by isporras          #+#    #+#             */
/*   Updated: 2024/02/21 15:29:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_status_var(char *lexer, char *tmp, int j)
{
	char	*value;
	char	*substr;

	value = ft_itoa(g_status);
	tmp = ft_strdup("");
	substr = ft_substr(lexer, 0, j);
	tmp = ft_strjoin(tmp, substr);
	free(substr);
	tmp = ft_strjoin(tmp, value);
	substr = ft_substr(lexer, j + 2, ft_strlen(lexer));
	tmp = ft_strjoin(tmp, substr);
	free(substr);
	free(value);
	return (tmp);
}

char	*ft_put_var2(char **lx, t_envp **envp, int *i, int *j)
{
	int		len;
	char	*var;
	char	*val;
	char	*tmp;

	len = 0;
	while (lx[*i][*j + 1 + len]
			&& lx[*i][*j + 1 + len] != ' '
			&& lx[*i][*j + 1 + len] != '\"')
		len++;
	var = ft_substr(lx[*i], *j + 1, len);
	val = find_env(envp, var);
	tmp = ft_calloc(ft_strlen(lx[*i]) - ft_strlen(var) + 2 + ft_strlen(val), 1);
	ft_strlcpy(tmp, lx[*i], *j + 1);
	if (val)
		tmp = ft_strjoin(tmp, val);
	else
		tmp = ft_strjoin(tmp, ft_strdup(""));
	tmp = ft_strjoin(tmp, &lx[*i][*j + ft_strlen(var) + 1]);
	free(var);
	return (tmp);
}

void	ft_put_var(char **lexer, int *i, int *j, t_envp **envp)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strncmp(&lexer[*i][*j], "$?", 2) == 0)
		tmp = ft_status_var(lexer[*i], tmp, *j);
	else
		tmp = ft_put_var2(lexer, envp, i, j);
	free(lexer[*i]);
	lexer[*i] = tmp;
}

//Extiende la variable global $ siempre que no esté entre comillas simples
void	ft_extend_var(char **lexer, t_envp **envp_list)
{
	int	i;
	int	j;
	int	q;

	q = 0;
	i = 0;
	while (lexer[i])
	{
		j = 0;
		while (lexer[i][j])
		{
			if (lexer[i][j] == '\'' && q == 0)
				q = 1;
			else if (lexer[i][j] == '\'' && q == 1)
				q = 0;
			if (lexer[i][j] == '$' && q == 0
				&& lexer[i][j + 1] != ' ' && lexer[i][j + 1] != '\0'
				&& ft_strncmp(lexer[i], "\"$\"", 3) != 0)
				ft_put_var(lexer, &i, &j, envp_list);
			j++;
		}
		i++;
	}
}

void	ft_lexer(t_lexer **lst_lexer, char **input, t_envp **envp_list)
{
	char	**str_lexer;

	if (!*input)
		return ;
	*input = ft_check_end_pipe(*input);
	str_lexer = ft_split_lexer(*input, ' ');
	ft_extend_var(str_lexer, envp_list);
	str_lexer = ft_get_tokens(str_lexer);
	str_lexer = ft_check_syntax(str_lexer);
	create_nodes(lst_lexer, str_lexer);
	ft_types(lst_lexer);
	ft_remove_quotes(lst_lexer);
	ft_free_2d(str_lexer);
}
