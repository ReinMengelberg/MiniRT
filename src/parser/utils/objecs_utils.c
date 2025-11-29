/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objecs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:48:08 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 15:51:27 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_color	*fill_color(char *token)
{
	char	**rgb;
	t_color	*col;

	rgb = ft_split(token, ',');
	if (!rgb || token_count(rgb) != 3)
	{
		free_tokens(rgb);
		return (NULL);
	}
	col = malloc(sizeof(t_color));
	if (!col)
	{
		free_tokens(rgb);
		return (NULL);
	}
	col->r = (unsigned char)ft_atoi(rgb[0]);
	col->g = (unsigned char)ft_atoi(rgb[1]);
	col->b = (unsigned char)ft_atoi(rgb[2]);
	free_tokens(rgb);
	if (col->r > 255 || col->g > 255 || col->b > 255)
	{
		free(col);
		return (printf("Error: Color values not in range [0,255]\n"), NULL);
	}
	return (col);
}

void	add_object_to_list(t_composition *comp, t_object *new_obj)
{
	t_object	*current;

	if (!comp->objects)
	{
		comp->objects = new_obj;
	}
	else
	{
		current = comp->objects;
		while (current->next)
			current = current->next;
		current->next = new_obj;
		new_obj->prev = current;
	}
}
