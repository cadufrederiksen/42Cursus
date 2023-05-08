/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:02:28 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/05 15:54:42 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newlst;

	if (!lst || !f)
		return (0);
	newlst = NULL;
	while (lst)
	{
		result = ft_lstnew(f(lst->content));
		if (!result)
		{
			ft_lstclear(&newlst, del);
			return (free(newlst), NULL);
		}
		ft_lstadd_back(&newlst, result);
		lst = lst->next;
	}
	return (newlst);
}
