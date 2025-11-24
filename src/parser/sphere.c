/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:27:32 by theyn             #+#    #+#             */
/*   Updated: 2025/11/24 15:51:27 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

bool	sphere_error(char **tokens, t_sphere *sph)
{
	char	*joined;

	joined = ft_strjoin_array(tokens, 4, " ");
	if (joined)
	{
		printf("Error: Incorrect sphere definition (%s) in .rt file\n", joined);
		free(joined);
	}
	else
		printf("Error: Incorrect sphere definition (unknown) in .rt file\n");
	free_tokens(tokens);
	free_sphere(sph);
	return (false);
}

bool	validate_sphere_values(t_sphere *sph, char **tokens)
{
	sph->root = fill_vector(tokens[1]);
	if (!sph->root)
		return (false);
	if (!is_valid_float(tokens[2]))
		return (false);
	sph->radius = ft_atod(tokens[2]) / 2;
	sph->color = fill_color(tokens[3]);
	if (!sph->color)
		return (false);
	return (true);
}

t_sphere	*parse_sphere(char **tokens)
{
	t_sphere	*sph;

	sph = malloc(sizeof(t_sphere));
	if (!sph)
	{
		printf("Error: Memory allocation for sphere failed\n");
		return (NULL);
	}
	sph->root = NULL;
	sph->color = NULL;
	if (!validate_sphere_values(sph, tokens))
	{
		free_sphere(sph);
		return (NULL);
	}
	return (sph);
}

t_object	*create_sphere_object(char **tokens)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
	{
		printf("Error: Memory allocation for sphere obj failed\n");
		return (NULL);
	}
	obj->type = SPHERE;
	obj->next = NULL;
	obj->prev = NULL;
	obj->data = parse_sphere(tokens);
	if (!obj->data)
	{
		free(obj);
		return (NULL);
	}
	return (obj);
}

bool	add_sphere(t_composition *comp, char *line)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error: Failed to split tokens for sphere\n"), false);
	if (token_count(tokens) != 4 || !check_token(tokens[0], "sp"))
	{
		free_tokens(tokens);
		return (printf("Error: Incorrect sphere definition\n"), false);
	}
	obj = create_sphere_object(tokens);
	free_tokens(tokens);
	if (!obj)
		return (printf("Error: Failed to parse sphere\n"), false);
	add_object_to_list(comp, obj);
	return (true);
}
