/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:14:54 by isporras          #+#    #+#             */
/*   Updated: 2024/02/17 17:35:25 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_add_token(char **src, int y, char *token, int d, int j)
{
	int		i;
	int		x;
	char	**dst;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char *) * (i + 3));
	i = 0;
	x = 0;
	while (src[i] && src[i][0] != '\0')
	{
		if (x == y && j == 0)
		{
			dst[x++] = ft_strdup(token);
			dst[x++] = ft_substr(src[i], d, ft_strlen(&src[i][d]));
			i++;
		}
		else if (x == y && j == ft_strlen(src[i]) - d)
		{
			dst[x++] = ft_substr(src[i], 0, ft_strlen(src[i]) - d);
			dst[x++] = ft_strdup(token);
			i++;
		}
		else if (x == y)
		{
			dst[x++] = ft_substr(src[i], 0, j);
			dst[x++] = ft_strdup(token);
			dst[x++] = ft_substr(src[i], j + d, ft_strlen(&src[i][j + d]));
			i++;
		}
		else
			dst[x++] = ft_strdup(src[i++]);
	}
	dst[x] = NULL;
	return (dst);
}

char	**ft_case_single_double(char **lexer, char *token, int *i, int *j)
{
	char	**tmp;

	if ((lexer[*i][*j] == '>' && lexer[*i][*j + 1] == '>')
		|| (lexer[*i][*j] == '<' && lexer[*i][*j + 1] == '<')
		|| (lexer[*i][*j] == '|' && lexer[*i][*j + 1] == '|'))
	{
		token = ft_substr(lexer[*i], *j, 2);
		tmp = ft_add_token(lexer, *i, token, 2, *j);
		(*j)++;
	}
	else
	{
		token = ft_substr(lexer[*i], *j, 1);
		tmp = ft_add_token(lexer, *i, token, 1, *j);
	}
	free(token);
	ft_free_2d(lexer);
	return (tmp);
}

char	**ft_get_tokens(char **lexer)
{
	int		i;
	int		j;
	char	*token;
	
	token = NULL;
	i = 0;
	while (lexer[i])
	{
		j = 0;
		while (lexer[i][j])
		{
			if ((lexer[i][j] == '>' || lexer[i][j] == '<' || lexer[i][j] == '|')
				&& (ft_strlen(lexer[i]) != 2) && (ft_between_quotes(lexer[i], j) == 0)
				&& ((ft_strncmp(&lexer[i][j], "<<", 2) == 0) || (ft_strncmp(&lexer[i][j], ">>", 2) == 0)
				|| (ft_strncmp(&lexer[i][j], "||", 2) == 0)))
					lexer = ft_case_single_double(lexer, token, &i, &j);
			else if ((lexer[i][j] == '>' || lexer[i][j] == '<' || lexer[i][j] == '|')
				&& (ft_strlen(lexer[i]) != 1) && (ft_between_quotes(lexer[i], j) == 0)
				&& (ft_strncmp(&lexer[i][j], "<<", 2) != 0) && (ft_strncmp(&lexer[i][j], ">>", 2) != 0)
				&& (ft_strncmp(&lexer[i][j], "||", 2) != 0) && (ft_strncmp(lexer[i], "<<", 3) != 0)
				&& (ft_strncmp(lexer[i], ">>", 3) != 0) && (ft_strncmp(lexer[i], "||", 3) != 0))
					lexer = ft_case_single_double(lexer, token, &i, &j);
			if (lexer[i][j])
				j++;
		}
		if (lexer[i])
			i++;
	}
	return (lexer);
}
