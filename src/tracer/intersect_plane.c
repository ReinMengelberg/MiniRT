/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/13 21:24:34 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/23 12:37:29 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

bool	intersect_plane(t_ray ray, t_plane *p, t_hit *hit)
{
	double	denom;
	double	t;
	t_vector	hit_point;

	denom = vdot(ray.direction, *p->direction);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vdot(vsub(*p->root, ray.root), *p->direction) / denom;
	if (t < 0.001)
		return (false);
	hit->t = t;
	hit_point = vadd(ray.root, vscale(ray.direction, t));
	hit->loc = malloc(sizeof(t_vector));
	*hit->loc = hit_point;
	hit->normal = malloc(sizeof(t_vector));
	*hit->normal = *p->direction;
	return (true);
}
