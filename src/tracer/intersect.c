/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:09:52 by theyn             #+#    #+#             */
/*   Updated: 2025/11/20 17:47:30 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	init_hit(t_hit *hit)
{
	hit->loc = NULL;
	hit->normal = NULL;
	hit->t = INFINITY;
}

static void	check_object_intersection(t_ray ray, object *obj, t_hit *temp_hit)
{
	if (obj->type == SPHERE)
		intersect_sphere(ray, (sphere *)obj->data, temp_hit);
	else if (obj->type == PLANE)
		intersect_plane(ray, (plane *)obj->data, temp_hit);
	else if (obj->type == CYLINDER)
		intersect_cylinder(ray, (cylinder *)obj->data, temp_hit);
}

static bool	update_if_closer(t_hit *hit, t_hit *temp_hit, object\
	*current, double *closest_t)
{
	if (temp_hit->t > 0.001 && temp_hit->t < *closest_t)
	{
		free_hit_data(hit);
		*closest_t = temp_hit->t;
		*hit = *temp_hit;
		hit->object = current->data;
		hit->type = current->type;
		return (true);
	}
	free_hit_data(temp_hit);
	return (false);
}

bool	find_intersect(t_ray ray, composition *comp, t_hit *hit)
{
	object	*current;
	t_hit	temp_hit;
	double	closest_t;
	bool	found;

	init_hit(hit);
	closest_t = INFINITY;
	found = false;
	current = comp->objects;
	while (current)
	{
		init_hit(&temp_hit);
		check_object_intersection(ray, current, &temp_hit);
		if (update_if_closer(hit, &temp_hit, current, &closest_t))
			found = true;
		current = current->next;
	}
	return (found);
}
