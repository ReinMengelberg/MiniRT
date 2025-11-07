#include "renderclanker.h"

void	free_composition(composition *comp) {
	if (!comp)
		return;
	if (comp->camera)
		free_camera(comp->camera);
	if (comp->ambient)
		free_ambient(comp->ambient);
	if (comp->objects)
		free_all_objects(comp->objects);
	if (comp->lights)
		free_all_lights(comp->lights);
	
	free(comp);
}

bool	add_to_composition(composition *comp, char *line)
{
	switch (line[0]) {
		case 'A':
			return (add_ambient(comp, line));
		case 'C':
			return (add_camera(comp, line));
		case 'L':
			return (add_light(comp, line));
		case 'p':
			return (add_plane(comp, line));
		case 's':
			return (add_sphere(comp, line));
		case 'c':
			return (add_cylinder(comp, line));
		default:
			return (dprintf(2, "Not a valid .rt file\n"), false);
	}
}

bool	validate_composition(composition *comp) {
	if (!comp->camera)
		return (dprintf(2, "Error: No camera defined in .rt file\n"), false);
	if (!comp->ambient)
		return (dprintf(2, "Error: No ambient defined in .rt file\n"), false);
	if (!comp->lights)
		return (dprintf(2, "Error: No lights defined in .rt file\n"), false);
	return (true);
}

composition	*create_composition(int fd) {
	composition	*comp;
	char		*line;
	
	comp = malloc(sizeof(composition));
	if (!comp)
		return (dprintf(2, "Error: Failed to allocate composition\n"), NULL);
	
	comp->camera = NULL;
	comp->ambient = NULL;
	comp->objects = NULL;
	comp->lights = NULL;

	while ((line = get_next_line(fd))) {
		if (line[ft_strlen(line) - 1] == '\n') { // Remove newline from next line
			line[ft_strlen(line) - 1] = '\0';
		}
		if (!add_to_composition(comp, line)) {
			free(line);
			free_composition(comp);
			return (NULL);
		}
		free(line);
	}
	if (!validate_composition(comp)) {
		return (free_composition(comp), NULL);
	}
	return (comp);
}
