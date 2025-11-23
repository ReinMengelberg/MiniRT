/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:35:30 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 13:25:40 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_shadow_hit(t_hit *shadow_hit)
{
	if (shadow_hit->loc)
		free(shadow_hit->loc);
	if (shadow_hit->normal)
		free(shadow_hit->normal);
}

bool	check_shadow_blocking(t_ray shadow_ray,
	t_composition *comp, double dist)
{
	t_hit	shadow_hit;
	bool	blocked;

	blocked = find_intersect(shadow_ray, comp, &shadow_hit);
	if (blocked && shadow_hit.t < dist)
	{
		free_shadow_hit(&shadow_hit);
		return (true);
	}
	if (blocked)
		free_shadow_hit(&shadow_hit);
	return (false);
}

bool	is_in_shadow(t_vector *hit_point, t_vector *light_pos,
	t_composition *comp)
{
	t_ray	shadow_ray;
	double	light_distance;

	shadow_ray.root = *hit_point;
	shadow_ray.direction = vnormalize(vsub(*light_pos, *hit_point));
	light_distance = vdistance(*hit_point, *light_pos);
	return (check_shadow_blocking(shadow_ray, comp, light_distance));
}
