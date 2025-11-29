/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:17:22 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 13:20:36 by theyn            ###   ########.fr       */
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

static bool	set_hit_data(t_hit *hit, t_cylinder *cyl, t_vector axis)
{
	t_vector	hit_point;

	hit_point = vadd(hit->ray.root, vscale(hit->ray.direction, hit->t));
	hit->loc = malloc(sizeof(t_vector));
	*hit->loc = hit_point;
	calculate_hit_normal(hit_point, cyl, axis, hit);
	return (true);
}

static bool	check_height_constraint(t_hit *hit, t_cylinder *cyl,
	t_vector axis)
{
	t_vector	oc;
	double		m;

	oc = vsub(hit->ray.root, *cyl->root);
	m = vdot(hit->ray.direction, axis) * hit->t + vdot(oc, axis);
	if (m >= 0 && m <= cyl->height)
		return (true);
	return (false);
}

bool	try_intersection(t_hit *hit, t_cylinder *cyl, t_vector axis)
{
	if (hit->t > 0.001)
		if (check_height_constraint(hit, cyl, axis))
			return (set_hit_data(hit, cyl, axis));
	return (false);
}
