#include "renderclanker.h"

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
			return (perror("Not a valid .rt file"), false);
	}
}

composition *create_composition(int fd) {
    composition	*comp;
    char		*line;
    
    comp = malloc(sizeof(composition));
    if (!comp)
        return (perror("Error: Failed to allocate composition"), NULL);
    
    comp->camera = NULL;
    comp->ambient = NULL;
    comp->objects = NULL;
    comp->lights = NULL;

    while ((line = get_next_line(fd))) {
        if (!add_to_composition(comp, line)) {
            free(line);
            free_composition(comp);
            return (NULL);
        }
        free(line);
    }
    return (comp);
}

void free_composition(composition *comp) {
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

