#include "renderclanker.h"

bool add_camera(composition *comp, char *line) {
	char    **tokens;

	if (comp->camera != NULL) {
		return (perror("Error: Multiple camera definitions in .rt file"), false);
	}
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for camera definition in .rt file"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "C")) {
		free_array(tokens);
		return (perror("Error: Incorrect camera definition in .rt file"), false);
	}
	
	comp->camera = parse_camera(tokens);
	free_array(tokens);
	if (!comp->camera) {
		return false;
	}
	return (true);
}

camera *parse_camera(char **tokens) {
	camera *cam;

	cam = malloc(sizeof(camera));
	if (!cam) {
		return (perror("Error: Failed to allocate memory for a camera"), NULL);
	}

	cam->root = fill_vector(tokens[1]);
	cam->direction = fill_direction(tokens[2]);
	cam->fov = ft_atoi(tokens[3]);

	if (!cam->root || !cam->direction || cam->fov > 180 || cam->fov < 0) {
		free_camera(cam);
		return (perror("Error: Incorrect camera definition in .rt file"), NULL);
	}	

	return cam;
}

void free_camera(camera *cam) {
	if (!cam)
		return;
	if (cam->root) free(cam->root);
	if (cam->direction) free(cam->direction);
	free(cam);
}