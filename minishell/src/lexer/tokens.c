/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:14:54 by isporras          #+#    #+#             */
/*   Updated: 2024/01/24 15:54:38 by carmarqu         ###   ########.fr       */
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
	dst = malloc(sizeof(char *) * (i + 2));
	i = 0;
	x = 0;
	while (src[i])
	{
		if (x == y && j == 0)//Valoramos si es la posición del token y si va al principio o final de la palabra
		{
			dst[x++] = token;
			dst[x++] = ft_substr(src[i], d, ft_strlen(&src[i][d]));
			i++;
		}
		else if (x == y && j != 0)
		{
			dst[x++] = ft_substr(src[i], 0, ft_strlen(src[i]) - d);
			dst[x++] = token;
			i++;
		}
		else
			dst[x++] = ft_strdup(src[i++]);
	}
	dst[x] = NULL;
	return (dst);
}

char	**ft_case_single_double(char	**lexer, char *token, int *i, int *j)
{
	char	**tmp;

	if ((lexer[*i][*j] == '>' && lexer[*i][*j + 1] == '>') //Valoramos si es un token doble
		|| (lexer[*i][*j] == '<' && lexer[*i][*j + 1] == '<')
		|| (lexer[*i][*j] == '|' && lexer[*i][*j + 1] == '|'))
	{
		token = ft_substr(lexer[*i], *j, 2);
		tmp = ft_add_token(lexer, *i, token, 2, *j);
		(*j)++;
	}
	else //Caso token simple
	{
		token = ft_substr(lexer[*i], *j, 1);
		tmp = ft_add_token(lexer, *i, token, 1, *j);
	}
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
				&& (j == 0 || j == ft_strlen(lexer[i]) - 2)
				&& ((ft_strncmp(&lexer[i][j], "<<", 2) == 0) || (ft_strncmp(&lexer[i][j], ">>", 2) == 0)
				|| (ft_strncmp(&lexer[i][j], "||", 2) == 0)))
				lexer = ft_case_single_double(lexer, token, &i, &j);
			else if ((lexer[i][j] == '>' || lexer[i][j] == '<' || lexer[i][j] == '|')//Valoramos si es un token situado al principio o el final de la palabra
				&& (ft_strlen(lexer[i]) != 1) && ((j == 0) || (j == ft_strlen(lexer[i]) - 1)))
				lexer = ft_case_single_double(lexer, token, &i, &j);
			j++;
		}
		i++;
	}
	return (lexer);
}