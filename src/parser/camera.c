#include "renderclanker.h"

void free_camera(camera *cam) {
	if (!cam)
		return;
	if (cam->root) free(cam->root);
	if (cam->direction) free(cam->direction);
	free(cam);
}

camera *parse_camera(char **tokens) {
	camera *cam;

	cam = malloc(sizeof(camera));
	if (!cam) {
		return (perror("Error: Failed to allocate memory for a camera"), NULL);
	}

	if (!is_valid_int(tokens[3]) || ft_atoi(tokens[3]) > 180 || ft_atoi(tokens[3] < 0)) goto error;
	cam->fov = ft_atoi(tokens[3]);

	cam->root = fill_vector(tokens[1]);
	if (!cam->root) goto error;

	cam->direction = fill_direction(tokens[2]);
	if (!cam->root) goto error;

	return cam;

error:
	free_camera(cam);
	return (perror("Error: Incorrect sphere definition in .rt file"), NULL);
}

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
		free_tokens(tokens);
		return (perror("Error: Incorrect camera definition in .rt file"), false);
	}
	
	comp->camera = parse_camera(tokens);
	free_tokens(tokens);
	if (!comp->camera) {
		return false;
	}
	return (true);
}