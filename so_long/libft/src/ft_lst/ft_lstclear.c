/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:39:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/05 13:54:25 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*newlst;

	while (*lst)
	{
		newlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = newlst;
	}
	*lst = NULL;
}
