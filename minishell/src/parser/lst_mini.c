/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:13:15 by carmarqu          #+#    #+#             */
/*   Updated: 2024/03/15 16:55:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_total_cmnds(t_mini **mini, int total_cmnds)
{
	int		i;
	t_mini	*aux;

	aux = *mini;
	i = 0;
	while (i < total_cmnds && aux)
	{
		aux->total_cmnds = total_cmnds;
		aux = aux->next;
		i++;
	}
}

t_mini	*ft_mini_new(int lap, t_envp **envp_list, int broken)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (0);
	mini->full_cmd = NULL;
	mini->full_path = NULL;
	mini->infile = STDIN_FILENO;
	mini->outfile = STDOUT_FILENO;
	mini->id = lap;
	mini->envp = envp_list;
	mini->broken = broken;
	mini->next = NULL;
	return (mini);
}

t_mini	*mini_last_list(t_mini *mini)
{
	if (!mini)
		return (0);
	while (mini->next != 0)
		mini = mini->next;
	return (mini);
}

void	mini_add_new(t_mini **mini, t_mini *new)
{
	t_mini	*aux;

	if (!new)
		return ;
	if (!*mini)
	{
		*mini = new;
		return ;
	}
	aux = mini_last_list(*mini);
	aux->next = new;
}

t_mini	**ft_to_mini_lst(t_lexer **lexer, t_mini **mini, t_envp **envp_list)
{
	t_lexer	*aux;
	int		lap;
	int		b;

	b = 0;
	lap = 0;
	aux = *lexer;
	while (aux)
	{
		if (aux->type == PIPE)
		{
			lap++;
			b = 0;
		}
		if ((aux->type == CMND || aux->type == GREATER) && b == 0)
		{
			mini_add_new(mini, ft_mini_new(lap, envp_list, aux->broken));
			b = 1;
		}
		aux = aux->next;
	}
	ft_total_cmnds(mini, lap + 1);
	return (mini);
}
