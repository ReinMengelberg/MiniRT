/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:04:52 by theyn             #+#    #+#             */
/*   Updated: 2024/10/18 18:01:03 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (lst && del)
	{
		while (*lst)
		{
			temp_node = (*lst)->next;
			del((*lst)->content);
			free (*lst);
			*lst = temp_node;
		}
		*lst = NULL;
	}
}
