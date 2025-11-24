/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:55:38 by theyn             #+#    #+#             */
/*   Updated: 2025/11/24 16:35:59 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_cylinder(t_cylinder *cyl)
{
	if (cyl->root)
		free(cyl->root);
	if (cyl->direction)
		free(cyl->direction);
	if (cyl->color)
		free(cyl->color);
	free(cyl);
}

bool	validate_cylinder_values(t_cylinder *cyl, char **tokens)
{
	cyl->root = fill_vector(tokens[1]);
	if (!cyl->root)
		return (false);
	cyl->direction = fill_direction(tokens[2]);
	if (!cyl->direction)
		return (false);
	if (!is_valid_float(tokens[3]))
		return (false);
	cyl->radius = ft_atod(tokens[3]) / 2;
	if (!is_valid_float(tokens[4]))
		return (false);
	cyl->height = ft_atod(tokens[4]);
	cyl->color = fill_color(tokens[5]);
	if (!cyl->color)
		return (false);
	return (cyl);
}

t_cylinder	*parse_cylinder(char **tokens)
{
	t_cylinder	*cyl;

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
	{
		return (printf("Error: Memory allocation for cyl\n"), NULL);
		return (NULL);
	}
	cyl->root = NULL;
	cyl->direction = NULL;
	cyl->color = NULL;
	if (!validate_cylinder_values(cyl, tokens))
	{
		free_cylinder(cyl);
		return (NULL);
	}
	return (cyl);
}

t_object	*create_cylinder_object(char **tokens)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
	{
		printf("Error: Memory allocation for cyl object\n");
		return (NULL);
	}
	obj->type = CYLINDER;
	obj->next = NULL;
	obj->prev = NULL;
	obj->data = parse_cylinder(tokens);
	if (!obj->data)
	{
		free(obj);
		return (NULL);
	}
	return (obj);
}

bool	add_cylinder(t_composition *comp, char *line)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error: Split tokens in cylinder"), false);
	if (token_count(tokens) != 6 || !check_token(tokens[0], "cy"))
	{
		free_tokens(tokens);
		return (printf("Incorrect cylinder definition\n"), false);
	}
	obj = create_cylinder_object(tokens);
	free_tokens(tokens);
	if (!obj)
		return (printf("Error: failed to parse cylinder\n"), false);
	add_object_to_list(comp, obj);
	return (true);
}
