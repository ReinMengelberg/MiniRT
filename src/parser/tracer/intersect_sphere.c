/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:13:56 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 13:25:13 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static double	calc_discriminant(t_ray ray, t_sphere *s, double *a, double *b)
{
	t_vector	oc;
	double		c;

	oc = vsub(ray.root, *s->root);
	*a = vdot(ray.direction, ray.direction);
	*b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - (s->radius * s->radius);
	return ((*b) * (*b) - 4 * (*a) * c);
}

static double	find_valid_t(double a, double b, double discriminant)
{
	double	t;

	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0.001)
		t = (-b + sqrt(discriminant)) / (2.0 * a);
	return (t);
}

static bool	populate_hit_data(t_ray ray, t_sphere *s, double t, t_hit *hit)
{
	t_vector	hit_point;

	if (t < 0.001)
		return (false);
	hit->t = t;
	hit_point = vadd(ray.root, vscale(ray.direction, t));
	hit->loc = malloc(sizeof(t_vector));
	if (!hit->loc)
		return (false);
	*hit->loc = hit_point;
	hit->normal = malloc(sizeof(t_vector));
	if (!hit->normal)
		return (free(hit->loc), false);
	*hit->normal = vnormalize(vsub(hit_point, *s->root));
	return (true);
}

bool	intersect_sphere(t_ray ray, t_sphere *s, t_hit *hit)
{
	double	a;
	double	b;
	double	discriminant;
	double	t;

	discriminant = calc_discriminant(ray, s, &a, &b);
	if (discriminant < 0)
		return (false);
	t = find_valid_t(a, b, discriminant);
	return (populate_hit_data(ray, s, t, hit));
}
