/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   composition.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/28 12:53:33 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/29 16:11:17 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_composition(t_composition *comp)
{
	if (!comp)
		return ;
	if (comp->camera)
		free_camera(comp->camera);
	if (comp->ambient)
		free_ambient(comp->ambient);
	if (comp->objects)
		free_all_objects(comp->objects);
	if (comp->lights)
		free_all_lights(comp->lights);
	if (comp->viewport)
		free_viewport(comp->viewport);
	free(comp);
}

bool	add_to_composition(t_composition *comp, char *line)
{
	if (line[0] == 'A')
		return (add_ambient(comp, line));
	else if (line[0] == 'C')
		return (add_camera(comp, line));
	else if (line[0] == 'L')
		return (add_light(comp, line));
	else if (line[0] == 'p' && line[1] == 'l')
		return (add_plane(comp, line));
	else if (line[0] == 's' && line[1] == 'p')
		return (add_sphere(comp, line));
	else if (line[0] == 'c' && line[1] == 'y')
		return (add_cylinder(comp, line));
	else
		return (printf("Error: Invalid object definition in .rt file: %s\n",
				line), false);
}

bool	validate_composition(t_composition *comp)
{
	if (!comp->camera)
		return (printf("Error: No camera defined in .rt file\n"), false);
	if (!comp->ambient)
		return (printf("Error: No ambient defined in .rt file\n"), false);
	if (!comp->lights)
		return (printf("Error: No lights defined in .rt file\n"), false);
	return (true);
}

static bool	process_line(t_composition *comp, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (!add_to_composition(comp, line))
	{
		free_composition(comp);
		return (false);
	}
	return (true);
}

t_composition	*create_composition(int fd)
{
	t_composition	*comp;
	char			*line;

	comp = malloc(sizeof(t_composition));
	if (!comp)
		return (printf("Error: Failed to allocate composition\n"), NULL);
	comp->camera = NULL;
	comp->ambient = NULL;
	comp->lights = NULL;
	comp->objects = NULL;
	comp->viewport = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_line(comp, line))
			return (free(line), NULL);
		free(line);
	}
	if (!validate_composition(comp))
		return (free_composition(comp), NULL);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
	return (comp);
}
