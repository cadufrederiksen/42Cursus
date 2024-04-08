/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:21:10 by isporras          #+#    #+#             */
/*   Updated: 2024/03/06 12:21:10 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_case_front(t_token *t, char **dst, int *x, int i)
{
	dst[(*x)++] = ft_strdup(t->tk);
	dst[(*x)++] = ft_substr(t->lx[i], t->d, ft_strlen(&t->lx[i][t->d]));
}

void	handle_case_behind(t_token *t, char **dst, int *x, int i)
{
	dst[(*x)++] = ft_substr(t->lx[i], 0, ft_strlen(t->lx[i]) - t->d);
	dst[(*x)++] = ft_strdup(t->tk);
}

void	handle_case_between(t_token *t, char **dst, int *x, int i)
{
	int	len;

	len = ft_strlen(&t->lx[i][t->j + t->d]);
	dst[(*x)++] = ft_substr(t->lx[i], 0, t->j);
	dst[(*x)++] = ft_strdup(t->tk);
	dst[(*x)++] = ft_substr(t->lx[i], t->j + t->d, len);
}

void	ft_add_token_switch(t_token *t, char **dst, int *x)
{
	int	i;

	i = 0;
	while (t->lx[i] && t->lx[i][0] != '\0')
	{
		if (*x == t->i && t->j == 0)
		{
			handle_case_front(t, dst, x, i);
			i++;
		}
		else if (*x == t->i && t->j == ft_strlen(t->lx[i]) - t->d)
		{
			handle_case_behind(t, dst, x, i);
			i++;
		}
		else if (*x == t->i)
		{
			handle_case_between(t, dst, x, i);
			i++;
		}
		else
			dst[(*x)++] = ft_strdup(t->lx[i++]);
	}
}

char	**ft_add_token(t_token *t)
{
	int		i;
	int		x;
	char	**dst;

	i = 0;
	while (t->lx[i])
		i++;
	dst = malloc(sizeof(char *) * (i + 3));
	if (!dst)
		return (0);
	x = 0;
	ft_add_token_switch(t, dst, &x);
	dst[x] = NULL;
	return (dst);
}
