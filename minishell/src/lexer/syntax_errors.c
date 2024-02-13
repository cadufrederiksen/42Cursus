/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:39:40 by isporras          #+#    #+#             */
/*   Updated: 2024/02/05 17:39:40 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_check_syntax(char **str_lexer)
{
	int	i;
	int	len;

	len = ft_count_lines2d(str_lexer);
	i = 0;
	while (str_lexer[i])
	{
		if (((ft_strncmp(str_lexer[i], "<", 2) == 0) || (ft_strncmp(str_lexer[i], ">", 2) == 0) 
			|| (ft_strncmp(str_lexer[i], "<<", 3) == 0) || (ft_strncmp(str_lexer[i], ">>", 3) == 0))
			&& (i == len - 1))
		{
			ft_syntax_error("syntax error near unexpected token `newline'");
			return (NULL);
		}
		i++;
	}
	return (str_lexer);
}
