/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:45:02 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 12:32:56 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_color	trace_ray(t_ray ray, t_composition *comp)
{
	t_hit	hit;
	bool	found;
	t_color	lit_color;

	found = find_intersect(ray, comp, &hit);
	if (!found)
		return (return_grey());
	lit_color = calculate_lighting(&hit, comp);
	free_hit_data(&hit);
	return (lit_color);
}
