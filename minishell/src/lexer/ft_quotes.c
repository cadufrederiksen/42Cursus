/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:52 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/17 16:08:01 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_between_quotes(char *str, int x)
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
	int		x;
	char	c;

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

void	ft_remove_quotes(t_lexer **lexer)
{
	char	**final;
	char	*no_quotes;
	t_lexer	*aux;
	int		i;
	char	c;

	aux = *lexer;
	while (aux)
	{
		c = which_quotes(aux->word);
		if (c)
		{
			no_quotes = ft_calloc(1, 1);
			i = 0;
			final = ft_split(aux->word, c);
			while (final[i])
				no_quotes = ft_strjoin(no_quotes, final[i++]);
			aux->word = ft_strdup(no_quotes);
			ft_free_2d(final);
			free(no_quotes);
		}
		if (which_quotes(aux->word))
			ft_remove_quotes(lexer);
		aux = aux->next;
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
			if (s[i] == '\0')
				return (1);
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"' && s[i] != '\0')
				i++;
			if (s[i] == '\0')
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
