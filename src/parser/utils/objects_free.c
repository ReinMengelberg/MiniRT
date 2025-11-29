/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:43:32 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 16:05:33 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_object_data(t_object *obj)
{
	if (!obj || !obj->data)
		return ;
	if (obj->type == SPHERE)
		free_sphere((t_sphere *)obj->data);
	else if (obj->type == CYLINDER)
		free_cylinder((t_cylinder *)obj->data);
	else if (obj->type == PLANE)
		free_plane((t_plane *)obj->data);
}

void	free_all_objects(t_object *objects)
{
	t_object	*current;
	t_object	*next;

	current = objects;
	while (current)
	{
		next = current->next;
		free_object_data(current);
		free(current);
		current = next;
	}
}
