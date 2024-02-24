/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:59 by isporras          #+#    #+#             */
/*   Updated: 2024/02/19 17:36:27 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_here_doc(t_mini *mini, char *eof)
{
	char	*line;
	int		fd[2];

	g_status = HEREDOC;
	pipe(fd);
	while (1 && g_status != EXIT_CMD)
	{
		line = readline("> ");
		if (line[0] != '\0' && line[0] != '\n')
		{
			if (ft_strncmp(line, eof, ft_strlen(eof)) == 0
				&& line[0] != '\n' && line)
			{
				free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
	}
	close(fd[1]);
	mini->infile = fd[0];
	g_status = HEREDOC_END;
}
