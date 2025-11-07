#include "renderclanker.h"

void free_plane(plane *pl) {
	if (pl->root) free(pl->root);
	if (pl->direction) free(pl->direction);
	if (pl->color) free(pl->color);
	free(pl);
}

plane	*parse_plane(char **tokens) {
	plane	*pl;

	pl = malloc(sizeof(plane));
	if (!pl) {
		return (perror("Failed to allocate memory for a plane"), NULL);
	}
	
	pl->root = fill_vector(tokens[1]);
	if (!pl->root) goto error;

	pl->direction = fill_direction(tokens[2]);
	if (!pl->direction) goto error;

	pl->color = fill_color(tokens[3]);
	if (!pl->color) goto error;

	return pl;
error:
	free_plane(pl);
	return (perror("Error: Incorrect plane definition in .rt file"), NULL);
}

bool add_plane(composition *comp, char *line) {
	char	**tokens;
	object	*new_obj;

	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for plane definition in .rt file"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "pl")) {
		free_tokens(tokens);
		return (perror("Incorrect cylinder definition in .rt file"), false);
    }

	new_obj = malloc(sizeof(object));
    if (!new_obj) {
        free_tokens(tokens);
        return (perror("Memory allocation failed"), false);
    }

	new_obj->type = PLANE;
	new_obj->data = parse_plane(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	if (!new_obj->data) {
		free(new_obj);
		return (perror("Failed to parse plane"), false);
	}

	add_object_to_list(comp, new_obj);
	return (true);
}
