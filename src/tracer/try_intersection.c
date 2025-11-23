/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_intersection.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 14:17:22 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/23 12:37:27 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	calculate_hit_normal(t_vector hit_point,
	t_cylinder *cyl, t_vector axis, t_hit *hit)
{
	t_vector	to_hit;
	t_vector	axis_component;

	to_hit = vsub(hit_point, *cyl->root);
	axis_component = vscale(axis, vdot(to_hit, axis));
	hit->normal = malloc(sizeof(t_vector));
	*hit->normal = vnormalize(vsub(to_hit, axis_component));
}

static bool	set_hit_data(t_ray ray, double t,
	t_cylinder *cyl, t_vector axis, t_hit *hit)
{
	t_vector	hit_point;

	hit->t = t;
	hit_point = vadd(ray.root, vscale(ray.direction, t));
	hit->loc = malloc(sizeof(t_vector));
	*hit->loc = hit_point;
	calculate_hit_normal(hit_point, cyl, axis, hit);
	return (true);
}

static bool	check_height_constraint(t_ray ray, double t,
	t_cylinder *cyl, t_vector axis)
{
	t_vector	oc;
	double	m;

	oc = vsub(ray.root, *cyl->root);
	m = vdot(ray.direction, axis) * t + vdot(oc, axis);
	if (m >= 0 && m <= cyl->height)
		return (true);
	return (false);
}

bool	try_intersection(t_ray ray, double t, t_cylinder *cyl,
	t_vector axis, t_hit *hit)
{
	if (t > 0.001)
		if (check_height_constraint(ray, t, cyl, axis))
			return (set_hit_data(ray, t, cyl, axis, hit));
	return (false);
}
