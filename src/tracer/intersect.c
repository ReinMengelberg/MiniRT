/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:09:52 by theyn             #+#    #+#             */
/*   Updated: 2025/11/09 14:33:28 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

bool intersect_sphere(t_ray ray, sphere *s, t_hit *hit)
{
	vector  oc;
	double  a, b, c, discriminant, t;
	vector  hit_point;

	// Vector from ray origin to sphere center
	oc = vsub(ray.root, *s->root);
	
	// Quadratic equation coefficients: at² + bt + c = 0
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (s->radius * s->radius);
	
	discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0)
		return (false);  // No intersection
	
	// Take the closest intersection point
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	
	if (t < 0.001)  // Behind camera or too close
		t = (-b + sqrt(discriminant)) / (2.0 * a);
	
	if (t < 0.001)
		return (false);
	
	hit->t = t;
	hit_point = vadd(ray.root, vscale(ray.direction, t));
	hit->loc = malloc(sizeof(vector));
	*hit->loc = hit_point;
	hit->normal = malloc(sizeof(vector));
	*hit->normal = vnormalize(vsub(hit_point, *s->root));
	return (true);
}

bool intersect_plane(t_ray ray, plane *p, t_hit *hit)
{
	double  denom, t;
	vector  hit_point;
	
	denom = vdot(ray.direction, *p->direction);
	
	if (fabs(denom) < 1e-6)  // Ray parallel to plane
		return (false);
	
	t = vdot(vsub(*p->root, ray.root), *p->direction) / denom;
	
	if (t < 0.001)  // Behind camera
		return (false);
	
	hit->t = t;
	hit_point = vadd(ray.root, vscale(ray.direction, t));
	hit->loc = malloc(sizeof(vector));
	*hit->loc = hit_point;
	hit->normal = malloc(sizeof(vector));
	*hit->normal = *p->direction;
	return (true);
}

bool intersect_cylinder(t_ray ray, cylinder *cyl, t_hit *hit)
{
	vector  oc;
	vector  dir_proj, oc_proj;
	double  a, b, c, discriminant, t1, t2;
	double  m;
	vector  hit_point;

	// Normalize cylinder axis
	vector axis = vnormalize(*cyl->direction);
	
	// Vector from ray origin to cylinder base
	oc = vsub(ray.root, *cyl->root);
	
	// Project ray direction and oc onto plane perpendicular to cylinder axis
	dir_proj = vsub(ray.direction, vscale(axis, vdot(ray.direction, axis)));
	oc_proj = vsub(oc, vscale(axis, vdot(oc, axis)));
	
	// Quadratic equation for infinite cylinder
	a = vdot(dir_proj, dir_proj);
	b = 2.0 * vdot(oc_proj, dir_proj);
	c = vdot(oc_proj, oc_proj) - (cyl->radius * cyl->radius);
	
	discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0)
		return (false);
	
	// Calculate both intersection points
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	
	// Check t1 first (closer intersection)
	if (t1 > 0.001)
	{
		m = vdot(ray.direction, axis) * t1 + vdot(oc, axis);
		if (m >= 0 && m <= cyl->height)
		{
			hit->t = t1;
			hit_point = vadd(ray.root, vscale(ray.direction, t1));
			hit->loc = malloc(sizeof(vector));
			*hit->loc = hit_point;
			
			// Normal is perpendicular to axis
			vector to_hit = vsub(hit_point, *cyl->root);
			vector axis_component = vscale(axis, vdot(to_hit, axis));
			hit->normal = malloc(sizeof(vector));
			*hit->normal = vnormalize(vsub(to_hit, axis_component));
			return (true);
		}
	}
	
	// Check t2 (farther intersection)
	if (t2 > 0.001)
	{
		m = vdot(ray.direction, axis) * t2 + vdot(oc, axis);
		if (m >= 0 && m <= cyl->height)
		{
			hit->t = t2;
			hit_point = vadd(ray.root, vscale(ray.direction, t2));
			hit->loc = malloc(sizeof(vector));
			*hit->loc = hit_point;
			
			vector to_hit = vsub(hit_point, *cyl->root);
			vector axis_component = vscale(axis, vdot(to_hit, axis));
			hit->normal = malloc(sizeof(vector));
			*hit->normal = vnormalize(vsub(to_hit, axis_component));
			return (true);
		}
	}
	
	return (false);
}

bool find_intersect(t_ray ray, composition *comp, t_hit *hit)
{
	object  *current;
	t_hit   temp_hit;
	double  closest_t = INFINITY;
	bool    found = false;

	hit->loc = NULL;
	hit->normal = NULL;
	hit->t = INFINITY;
	current = comp->objects;
	
	while (current)
	{
		temp_hit.loc = NULL;
		temp_hit.normal = NULL;
		temp_hit.t = INFINITY;
		
		if (current->type == SPHERE)
			intersect_sphere(ray, (sphere *)current->data, &temp_hit);
		else if (current->type == PLANE)
			intersect_plane(ray, (plane *)current->data, &temp_hit);
		else if (current->type == CYLINDER)
			intersect_cylinder(ray, (cylinder *)current->data, &temp_hit);
		
		// Keep track of closest intersection
		if (temp_hit.t > 0.001 && temp_hit.t < closest_t)
		{
			// Free previous hit data if it exists
			if (hit->loc)
				free(hit->loc);
			if (hit->normal)
				free(hit->normal);
			
			closest_t = temp_hit.t;
			*hit = temp_hit;
			hit->object = current->data;
			hit->type = current->type;
			found = true;
		}
		else
		{
			// Free unused temp_hit data
			if (temp_hit.loc)
				free(temp_hit.loc);
			if (temp_hit.normal)
				free(temp_hit.normal);
		}
		current = current->next;
	}
	return (found);
}