/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:45:04 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 14:45:54 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_camera(t_camera *cam)
{
	if (!cam)
		return ;
	if (cam->root)
		free(cam->root);
	if (cam->direction)
		free(cam->direction);
	free(cam);
}

t_camera	*camera_error(t_camera *cam, char **tokens)
{
	char	*joined;

	joined = ft_strjoin_array(tokens, 4, " ");
	if (joined)
	{
		printf("Error: Incorrect camera definition (%s) in .rt file\n", joined);
		free(joined);
	}
	else
	{
		printf("Error: Incorrect camera definition (unknown) in .rt file\n");
	}
	free_camera(cam);
	return (NULL);
}

t_camera	*parse_camera(char **tokens)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
	{
		printf("Error: Failed to allocate memory for a camera\n");
		return (NULL);
	}
	cam->root = fill_vector(tokens[1]);
	if (!cam->root)
		return (camera_error(cam, tokens));
	cam->direction = fill_direction(tokens[2]);
	if (!cam->direction)
		return (camera_error(cam, tokens));
	if (!is_valid_int(tokens[3]))
		return (camera_error(cam, tokens));
	cam->fov = ft_atoi(tokens[3]);
	if (cam->fov < 0 || cam->fov > 180)
		return (camera_error(cam, tokens));
	return (cam);
}

bool	add_camera(t_composition *comp, char *line)
{
	char	**tokens;

	if (comp->camera != NULL)
	{
		printf("Error: Multiple camera definitions in .rt file\n");
		return (false);
	}
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		printf("Error: Failed to split tokens for\
			camera definition in .rt file\n");
		return (false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "C"))
	{
		free_tokens(tokens);
		printf("Error: Incorrect camera definition in .rt file\n");
		return (false);
	}
	comp->camera = parse_camera(tokens);
	free_tokens(tokens);
	if (!comp->camera)
		return (false);
	return (true);
}
