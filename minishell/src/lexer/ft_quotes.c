/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:52 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/12 13:32:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_between_quotes(char *str, int x)//Devuelve 1 si el elemento buscado está entre comillas simples o dobles
{
	char	quote;
	int		i;

	quote = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
			{
				if (i++ == x)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char	which_quotes(char *str)
{
	int x;
	char c;

	x = 0;
	while (str[x])
	{
		if (str[x] == '\'' || str[x] == '\"')
		{
			c = str[x++];
			while (str[x])
			{
				if (str[x++] == c)
					return (c);
			}
		}
		x++;
	}
	return (0);
}

void	ft_remove_quotes(char **str_lexer)
{
	char	**final;
	char	*no_quotes;
	int		x;
	int 	i;
	char c;

	x = 0;
	while (str_lexer[x])
	{
		c = which_quotes(str_lexer[x]);//que tipo dequotes es
		if (c)
		{
			no_quotes = ft_calloc(1, 1);
			i = 0;
			final = ft_split(str_lexer[x], c);//divide str a cada quote
			while(final[i])
			{
				no_quotes = ft_strjoin(no_quotes, final[i]);//hace un join de todo
				i++;
			}
			str_lexer[x] = ft_strdup(no_quotes);
			ft_free_2d(final);
			free(no_quotes);
		}
		if (which_quotes(str_lexer[x]))//si todavia hay algo que quitar
			ft_remove_quotes(str_lexer);
		x++;
	}
}

int	ft_check_open_quotes(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
			if(s[i] == '\0')
				return (1);
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"' && s[i] != '\0')
				i++;
			if(s[i] == '\0')
				return (2);
		}
		i++;
	}
	return (0);
}

void	ft_quotes_input(char **input)
{
	char	*new_input;
	char	*prompt;

	while (ft_check_open_quotes(*input) > 0)
	{
		if (ft_check_open_quotes(*input) == 1)
			prompt = "quotes>";
		else
			prompt = "dquotes>";
		new_input = readline(prompt);
		if (new_input)
			*input = ft_strjoin(*input, new_input);
	}
}
