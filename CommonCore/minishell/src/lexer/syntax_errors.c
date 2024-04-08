/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:39:40 by isporras          #+#    #+#             */
/*   Updated: 2024/03/12 16:41:13 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_end_pipe(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	i--;
	while (i > 0 && input[i] == ' ')
		i--;
	if (input[i] == '|')
		return (1);
	else
		return (0);
}

char	*ft_check_end_pipe(char *input)
{
	char	*new_input;

	g_status = HEREDOC;
	while (ft_end_pipe(input) == 1 && g_status != EXIT_CMD)
	{
		new_input = readline(">");
		if (new_input)
		{
			input = ft_strjoin(input, new_input);
			free(new_input);
		}
	}
	g_status = HEREDOC_END;
	return (input);
}

char	**ft_check_syntax(char **str_lexer)
{
	int	i;
	int	len;

	len = ft_count_lines2d(str_lexer);
	i = 0;
	while (str_lexer[i])
	{
		if (((ft_strncmp(str_lexer[i], "<", 2) == 0)
				|| (ft_strncmp(str_lexer[i], ">", 2) == 0)
				|| (ft_strncmp(str_lexer[i], "<<", 3) == 0)
				|| (ft_strncmp(str_lexer[i], ">>", 3) == 0))
			&& (i == len - 1))
		{
			ft_syntax_error("syntax error near unexpected token `newline'");
			return (NULL);
		}
		if ((ft_strncmp(str_lexer[i], "|", 2) == 0) && (i == 0))
		{
			ft_syntax_error("syntax error near unexpected token `|'");
			return (NULL);
		}
		i++;
	}
	return (str_lexer);
}
