/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:22:31 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 16:26:29 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	add_light_to_linked_list(t_composition *comp, t_light *new_light)
{
	t_light	*current;

	if (!comp->lights)
		comp->lights = new_light;
	else
	{
		current = comp->lights;
		while (current->next)
			current = current->next;
		current->next = new_light;
		new_light->prev = current;
	}
}

void	free_light(t_light *light)
{
	if (!light)
		return ;
	if (light->root)
		free(light->root);
	if (light->color)
		free(light->color);
	free(light);
}

void	free_all_lights(t_light *lights)
{
	t_light	*current;
	t_light	*next;

	current = lights;
	while (current)
	{
		next = current->next;
		free_light(current);
		current = next;
	}
}

bool	validate_light_values(t_light *light, char **tokens)
{
	light->root = fill_vector(tokens[1]);
	if (!light->root)
		return (false);
	if (!is_valid_float(tokens[2]))
		return (false);
	light->brightness = ft_atof(tokens[2]);
	if (light->brightness < 0 || light->brightness > 1)
		return (false);
	light->color = fill_color(tokens[3]);
	if (!light->color)
		return (false);
	return (true);
}
