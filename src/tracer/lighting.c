/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/20 17:41:49 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/23 12:36:49 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	add_diffuse_light(t_color *final_color, t_color *obj_color,
	t_vector *light_dir, t_hit *hit)
{
	double	diffuse;

	diffuse = vdot(*hit->normal, *light_dir);
	if (diffuse > 0)
	{
		final_color->r += obj_color->r * diffuse;
		final_color->g += obj_color->g * diffuse;
		final_color->b += obj_color->b * diffuse;
	}
}

void	apply_light_contribution(t_color *final_color, t_light *current_light,
		t_hit *hit, t_color *obj_color)
{
	t_vector	light_dir;
	double	diffuse;
	double	contribution;

	light_dir = vnormalize(vsub(*current_light->root, *hit->loc));
	diffuse = vdot(*hit->normal, light_dir);
	if (diffuse > 0)
	{
		contribution = diffuse * current_light->brightness;
		final_color->r += obj_color->r * contribution;
		final_color->g += obj_color->g * contribution;
		final_color->b += obj_color->b * contribution;
	}
}

t_color	process_lights(t_hit *hit, t_composition *comp, t_color *obj_color,
		t_color final_color)
{
	t_light	*current_light;

	current_light = comp->lights;
	while (current_light)
	{
		if (!is_in_shadow(hit->loc, current_light->root, comp))
			apply_light_contribution(&final_color, current_light,
				hit, obj_color);
		current_light = current_light->next;
	}
	clamp_color_values(&final_color);
	return (final_color);
}

t_color	calculate_lighting(t_hit *hit, t_composition *comp)
{
	t_color	final_color;
	t_color	*obj_color;
	double	ambient_intensity;

	obj_color = get_object_color(hit);
	if (!obj_color)
		return (return_grey());
	ambient_intensity = comp->ambient->intensity;
	final_color = init_ambient_color(obj_color, ambient_intensity);
	return (process_lights(hit, comp, obj_color, final_color));
}
