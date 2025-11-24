/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:28:17 by theyn             #+#    #+#             */
/*   Updated: 2025/11/24 15:26:43 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

bool	plane_error(char **tokens, t_plane *pl)
{
	char	*joined;

	joined = ft_strjoin_array(tokens, 4, " ");
	if (joined)
	{
		printf("Error: Incorrect plane definition (%s) in .rt file\n", joined);
		free(joined);
	}
	else
		printf("Error: Incorrect plane definition (unknown) in .rt file\n");
	free_tokens(tokens);
	free_plane(pl);
	return (false);
}

bool	validate_plane_values(t_plane *pl, char **tokens)
{
	pl->root = fill_vector(tokens[1]);
	if (!pl->root)
		return (false);
	pl->direction = fill_direction(tokens[2]);
	if (!pl->direction)
		return (false);
	pl->color = fill_color(tokens[3]);
	if (!pl->color)
		return (false);
	return (true);
}

t_plane	*parse_plane(char **tokens)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (!pl)
	{
		printf("Error: Memory allocation for plane failed\n");
		return (NULL);
	}
	pl->root = NULL;
	pl->direction = NULL;
	pl->color = NULL;
	if (!validate_plane_values(pl, tokens))
	{
		free_plane(pl);
		return (NULL);
	}
	return (pl);
}

t_object	*create_plane_object(char **tokens)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
	{
		printf("Error: Memory allocation for plane obj failed\n");
		return (NULL);
	}
	obj->type = PLANE;
	obj->next = NULL;
	obj->prev = NULL;
	obj->data = parse_plane(tokens);
	if (!obj->data)
	{
		free(obj);
		return (NULL);
	}
	return (obj);
}

bool	add_plane(t_composition *comp, char *line)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error: Failed to split tokens for plane\n"), false);
	if (token_count(tokens) != 4 || !check_token(tokens[0], "pl"))
	{
		free_tokens(tokens);
		return (printf("Error: Incorrect plane definition\n"), false);
	}
	obj = create_plane_object(tokens);
	free_tokens(tokens);
	if (!obj)
		return (printf("Error: Failed to parse plane\n"), false);
	add_object_to_list(comp, obj);
	return (true);
}
