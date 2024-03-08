/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:00:49 by carmarqu          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:06 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char const	*ft_skip_quotes(char const *s, int *i, int *b)
{
	if (s[(*i)] == '\'')
	{
		(*i)++;
		while (s[*i] != '\'' && s[*i] != '\0')
			(*i)++;
	}
	else if (s[*i] == '\"')
	{
		(*i)++;
		while (s[*i] != '\"' && s[*i] != '\0')
			(*i)++;
	}
	*b = 1;
	if (s[*i] == '\0')
		return (NULL);
	else
		return (s);
}

int	ft_count_split(char const *s)
{
	int	i;
	int	b;
	int	n;

	n = 0;
	b = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			b = 0;
		if (s[i] == '\'' || s[i] == '\"')
		{
			if (ft_skip_quotes(s, &i, &b) == NULL)
				return (-1);
			n++;
		}
		if (s[i] != ' ' && b == 0)
		{
			n++;
			b = 1;
		}
		i++;
	}
	return (n);
}

void	ft_malloc_quotes(char const *s, int *i, int *j, char **str)
{
	int	len;

	len = 0;
	if (s[*i + len] == '\'')
	{
		len++;
		while (s[*i + len] != '\'' && s[*i + len] != '\0')
			len++;
		while (s[*i + len] != ' ' && s[*i + len] != '\0')
			len++;
	}
	else if (s[*i] == '\"')
	{
		len++;
		while ((s[*i + len] != '\"' || s[*i + len] != ' ')
			&& s[*i + len] != '\0')
			len++;
	}
	if (s[*i + len] == '\'' || s[*i + len] == '\"')
		len++;
	str[*j] = (char *)malloc(sizeof(char) * (len + 1));
	if (!str[*j])
		return ;
	ft_strlcpy(str[*j], s + *i, len + 1);
	*i += len;
}

void	ft_malloc_no_quotes(char const *s, int *i, int *j, char **str)
{
	int	len;

	len = 0;
	while (s[*i + len] != ' ' && s[*i + len] != '\0')
	{
		len++;
		if (s[*i + len] == '\"')
		{
			len++;
			while (s[*i + len] != '\"' && s[*i + len] != '\0')
				len++;
		}
		else if (s[*i + len] == '\'')
		{
			len++;
			while (s[*i + len] != '\'' && s[*i + len] != '\0')
				len++;
		}
	}
	str[*j] = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(str[*j], s + *i, len + 1);
	*i += len;
}

char	**ft_split_lexer(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count_split(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'' || s[i] == '\"')
			ft_malloc_quotes(s, &i, &j, str);
		else
			ft_malloc_no_quotes(s, &i, &j, str);
		j++;
	}
	str[j] = NULL;
	return (str);
}
