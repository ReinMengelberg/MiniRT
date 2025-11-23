#include "renderclanker.h"

void free_cylinder(t_cylinder *cyl) {
	if (cyl->root) free(cyl->root);
	if (cyl->direction) free(cyl->direction);
	if (cyl->color) free(cyl->color);
	free(cyl);
}

t_cylinder *parse_cylinder(char **tokens) {
	t_cylinder *cyl;

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl) {
		return (dprintf(2, "Failed to allocate memory for a cylinder\n"), NULL);
	}

	cyl->root = fill_vector(tokens[1]);
	if (!cyl->root) goto error;

	cyl->direction = fill_direction(tokens[2]);
	if (!cyl->direction) goto error;

	if (!is_valid_float(tokens[3])) goto error;
	cyl->radius = ft_atod(tokens[3]) / 2;

	if (!is_valid_float(tokens[4])) goto error;
	cyl->height = ft_atod(tokens[4]);

	cyl->color = fill_color(tokens[5]);
	if (!cyl->color) goto error;
	return cyl;

error:
	free_cylinder(cyl);
	char *joined = ft_strjoin_array(tokens, 6, " ");
	dprintf(2, "Error: Incorrect cylinder definition (%s) in .rt file\n", joined ? joined : "unknown");
	return (free(joined), NULL);
}

bool add_cylinder(t_composition *comp, char *line) {
	char    **tokens;
	t_object  *new_obj;
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (dprintf(2, "Error: Failed to split tokens for cylinder definition in .rt file\n"), false);
	}
	if (token_count(tokens) != 6 || !check_token(tokens[0], "cy")) {
		free_tokens(tokens);
		return (dprintf(2, "Incorrect cylinder definition in .rt file\n"), false);
	}
	
	// Create new object node
	new_obj = malloc(sizeof(t_object));
	if (!new_obj) {
		free_tokens(tokens);
		return (dprintf(2, "Memory allocation failed\n"), false);
	}

	new_obj->type = CYLINDER;
	new_obj->data = parse_cylinder(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	// Check if parse_cylinder failed
	if (!new_obj->data) {
		free(new_obj);
		return (dprintf(2, "Failed to parse cylinder\n"), false);
	}
	
	add_object_to_list(comp, new_obj);
	return (true);
}
