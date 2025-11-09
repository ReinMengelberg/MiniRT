/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:45:02 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/09 12:39:27 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

color	return_grey()
{
	color	gray;

	gray.r = 128;
	gray.g = 128;
	gray.b = 128;
	
	return (gray);
}

double	intersect_sphere(t_ray ray, sphere *sp)
{

}

double	intersect_plane(t_ray ray, plane *pl)
{

}

double	intersect_cylinder(t_ray ray, cylinder *cyl)
{

}

color	calculate_lighting(t_hit_info hit, composition *comp)
{

}

color	trace_ray(t_ray ray, composition *comp)
{
	t_hit_info	hit;

	if (!find_closest_intersection(ray, comp, &hit))
		return (return_grey());
	return (calculate_lighting(hit, comp));
}


object	*find_closest_intersection(t_ray ray, composition *comp, double *t)
{
	object	*current;
	object	*closest;
	double	closest_t;
	double	temp_t;

	closest = NULL;
	closest_t = INFINITY;
	current = comp->objects;
	while (current)
	{
		if (current->type == SPHERE)
			temp_t = intersect_sphere(ray, (sphere *)current->data);
		else if (current->type == PLANE)
			temp_t = intersect_plane(ray, (plane *)current->data);
		else if (current->type == CYLINDER)
			temp_t = intersect_cylinder(ray, (cylinder *)current->data);
		if (temp_t > 0.001 && temp_t < *t)
		{
			*t = temp_t;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}
