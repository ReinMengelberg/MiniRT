#include "renderclanker.h"

void free_plane(plane *plane) {
	if (plane->root) free(plane->root);
	if (plane->direction) free(plane->direction);
	if (plane->color) free(plane->color);
	free(plane);
}

plane	*parse_plane(char **tokens) {
	plane	*plane;

	plane = malloc(sizeof(plane));
	if (!plane) {
		return (perror("Failed to allocate memory for a plane"), NULL);
	}
	
	plane->root = fill_vector(tokens[1]);
	plane->direction = fill_direction(tokens[2]);
	plane->color = fill_color(tokens[3]);

	if (!plane->root || !plane->direction || !plane->color){
		free_plane(plane);
		return (perror("Incorrect plane definition in .rt file"), NULL);
	}	

	return plane;
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
