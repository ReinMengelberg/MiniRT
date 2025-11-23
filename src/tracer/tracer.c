/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:45:02 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/20 17:44:34 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

color	trace_ray(t_ray ray, composition *comp)
{
	t_hit	hit;
	bool	found;
	color	lit_color;

	found = find_intersect(ray, comp, &hit);
	if (!found)
		return (return_grey());
	lit_color = calculate_lighting(&hit, comp);
	free_hit_data(&hit);
	return (lit_color);
}
