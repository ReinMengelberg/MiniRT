#include "renderclanker.h"

void free_camera(t_camera *cam) {
	if (!cam)
		return;
	if (cam->root) free(cam->root);
	if (cam->direction) free(cam->direction);
	free(cam);
}

t_camera *parse_camera(char **tokens) {
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	if (!cam) {
		return (dprintf(2, "Error: Failed to allocate memory for a camera\n"), NULL);
	}

	cam->root = fill_vector(tokens[1]);
	if (!cam->root) goto error;

	cam->direction = fill_direction(tokens[2]);
	if (!cam->direction) goto error;

	if (!is_valid_int(tokens[3])) goto error;
	cam->fov = ft_atoi(tokens[3]);
	if (cam->fov > 180 || cam->fov < 0) goto error;
	
	return cam;

error:
	free_camera(cam);
	char *joined = ft_strjoin_array(tokens, 4, " ");
	dprintf(2, "Error: Incorrect camera definition (%s) in .rt file\n", joined ? joined : "unknown");
	return (free(joined), NULL);
}

bool add_camera(t_composition *comp, char *line) {
	char    **tokens;
	
	if (comp->camera != NULL) {
		return (dprintf(2, "Error: Multiple camera definitions in .rt file\n"), false);
	}
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (dprintf(2, "Error: Failed to split tokens for camera definition in .rt file\n"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "C")) {
		free_tokens(tokens);
		return (dprintf(2, "Error: Incorrect camera definition in .rt file\n"), false);
	}
	
	comp->camera = parse_camera(tokens);
	free_tokens(tokens);
	if (!comp->camera) {
		return false;
	}
	return (true);
}