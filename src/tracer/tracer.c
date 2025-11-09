/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:45:02 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/09 15:10:09 by theyn            ###   ########.fr       */
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

color	return_red()
{
	color	gray;

	gray.r = 255;
	gray.g = 0;
	gray.b = 0;
	
	return (gray);
}

color	return_green()
{
	color	gray;

	gray.r = 0;
	gray.g = 255;
	gray.b = 0;
	
	return (gray);
}

color	return_blue()
{
	color	gray;

	gray.r = 0;
	gray.g = 0;
	gray.b = 0;
	
	return (gray);
}

color calculate_lighting(t_hit *hit, composition *comp)
{
	color	final_color;
	color	*obj_color;
	light	*current_light;
	vector	light_dir;
	double	diffuse;
	double	ambient_intensity;
	double	light_contribution;
	
	// Get object color based on type
	if (hit->type == SPHERE)
		obj_color = ((sphere *)hit->object)->color;
	else if (hit->type == PLANE)
		obj_color = ((plane *)hit->object)->color;
	else if (hit->type == CYLINDER)
		obj_color = ((cylinder *)hit->object)->color;
	else
		return (return_grey());
	
	// Start with ambient light
	ambient_intensity = comp->ambient->intensity;
	final_color.r = obj_color->r * ambient_intensity;
	final_color.g = obj_color->g * ambient_intensity;
	final_color.b = obj_color->b * ambient_intensity;
	
	// Add contribution from each light source
	current_light = comp->lights;
	while (current_light)
	{
		// Vector from hit point to light
		light_dir = vnormalize(vsub(*current_light->root, *hit->loc));
		
		// Diffuse lighting (Lambertian)
		diffuse = vdot(*hit->normal, light_dir);
		if (diffuse > 0)
		{
			light_contribution = diffuse * current_light->brightness;
			final_color.r += obj_color->r * light_contribution;
			final_color.g += obj_color->g * light_contribution;
			final_color.b += obj_color->b * light_contribution;
		}
		current_light = current_light->next;
	}
	
	// Clamp values to 0-255
	if (final_color.r > 255) final_color.r = 255;
	if (final_color.g > 255) final_color.g = 255;
	if (final_color.b > 255) final_color.b = 255;
	
	return (final_color);
}

color	trace_ray(t_ray ray, composition *comp)
{
	t_hit	hit;
	bool	found;
	color	lit_color;
	
	found = find_intersect(ray, comp, &hit);
	if (!found)
		return (return_grey());
	
	// Calculate lighting based on the hit
	lit_color = calculate_lighting(&hit, comp);
	
	// Free the hit data
	if (hit.loc)
		free(hit.loc);
	if (hit.normal)
		free(hit.normal);
	
	return (lit_color);
}

// color	trace_ray(t_ray ray, composition *comp)
// {
// 	t_hit	hit;
// 	bool	found;
	
// 	found = find_intersect(ray, comp, &hit);
// 	if (!found)
// 		return (return_grey());
	
// 	if (hit.type == SPHERE)
// 		return (*((sphere *)hit.object)->color);
// 	else if (hit.type == PLANE)
// 		return (*((plane *)hit.object)->color);
// 	else if (hit.type == CYLINDER)
// 		return (*((cylinder *)hit.object)->color);
// 	return (return_grey());
// }
