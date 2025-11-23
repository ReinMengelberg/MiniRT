#include "renderclanker.h"

void free_plane(t_plane *pl) {
	if (pl->root) free(pl->root);
	if (pl->direction) free(pl->direction);
	if (pl->color) free(pl->color);
	free(pl);
}

t_plane	*parse_plane(char **tokens) {
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (!pl) {
		return (dprintf(2, "Failed to allocate memory for a plane\n"), NULL);
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
	char *joined = ft_strjoin_array(tokens, 4, " ");
	dprintf(2, "Error: Incorrect plane definition (%s) in .rt file\n", joined ? joined : "unknown");
	return (free(joined), NULL);
}

bool add_plane(t_composition *comp, char *line) {
	char	**tokens;
	t_object	*new_obj;

	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (dprintf(2, "Error: Failed to split tokens for plane definition in .rt file\n"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "pl")) {
		free_tokens(tokens);
		return (dprintf(2, "Incorrect cylinder definition in .rt file\n"), false);
    }

	new_obj = malloc(sizeof(t_object));
    if (!new_obj) {
        free_tokens(tokens);
        return (dprintf(2, "Memory allocation failed\n"), false);
    }

	new_obj->type = PLANE;
	new_obj->data = parse_plane(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	if (!new_obj->data) {
		free(new_obj);
		return (dprintf(2, "Failed to parse plane\n"), false);
	}

	add_object_to_list(comp, new_obj);
	return (true);
}
