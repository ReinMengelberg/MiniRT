/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:45:02 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/14 14:54:10 by theyn            ###   ########.fr       */
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

bool is_in_shadow(vector *hit_point, vector *light_pos, composition *comp)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	double	light_distance;
	bool	blocked;
	
	// Create ray from hit point toward light
	shadow_ray.root = *hit_point;
	shadow_ray.direction = vnormalize(vsub(*light_pos, *hit_point));
	
	// Calculate distance to light
	light_distance = vdistance(*hit_point, *light_pos);
	
	// Check if anything blocks the path to the light
	blocked = find_intersect(shadow_ray, comp, &shadow_hit);
	
	if (blocked && shadow_hit.t < light_distance)
	{
		// Something is between hit point and light - we're in shadow
		if (shadow_hit.loc)
			free(shadow_hit.loc);
		if (shadow_hit.normal)
			free(shadow_hit.normal);
		return (true);
	}
	
	// Clean up if we found an intersection beyond the light
	if (blocked)
	{
		if (shadow_hit.loc)
			free(shadow_hit.loc);
		if (shadow_hit.normal)
			free(shadow_hit.normal);
	}
	
	return (false);
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
		// Check if this point is in shadow from this light
		if (is_in_shadow(hit->loc, current_light->root, comp))
		{
			current_light = current_light->next;
			continue;  // Skip this light, it's blocked
		}
		
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
