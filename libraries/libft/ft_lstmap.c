/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:03 by theyn             #+#    #+#             */
/*   Updated: 2024/10/19 12:38:39 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*start;
	void	*content;

	start = NULL;
	if (f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content = (*f)(lst->content);
		new_list = ft_lstnew(content);
		if (!new_list)
		{
			ft_lstclear(&start, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&start, new_list);
		lst = lst->next;
	}
	return (start);
}
