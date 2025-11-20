/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:45:07 by theyn             #+#    #+#             */
/*   Updated: 2025/11/20 17:50:24 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

color	return_grey(void)
{
	color	gray;

	gray.r = 128;
	gray.g = 128;
	gray.b = 128;
	return (gray);
}

color	*get_object_color(t_hit *hit)
{
	if (hit->type == SPHERE)
		return (((sphere *)hit->object)->color);
	else if (hit->type == PLANE)
		return (((plane *)hit->object)->color);
	else if (hit->type == CYLINDER)
		return (((cylinder *)hit->object)->color);
	return (NULL);
}

color	init_ambient_color(color *obj_color, double ambient_intensity)
{
	color	final_color;

	final_color.r = obj_color->r * ambient_intensity;
	final_color.g = obj_color->g * ambient_intensity;
	final_color.b = obj_color->b * ambient_intensity;
	return (final_color);
}

void	clamp_color_values(color *final_color)
{
	if (final_color->r > 255)
		final_color->r = 255;
	if (final_color->g > 255)
		final_color->g = 255;
	if (final_color->b > 255)
		final_color->b = 255;
}

void	free_hit_data(t_hit *hit)
{
	if (hit->loc)
		free(hit->loc);
	if (hit->normal)
		free(hit->normal);
}
