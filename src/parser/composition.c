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

	while ((line = get_next_lint(fd))) {
		if (!add_to_composition(comp, line)) {
			// collect garbage
			free(line);
		}
		free(line);
	}
	return 
}

