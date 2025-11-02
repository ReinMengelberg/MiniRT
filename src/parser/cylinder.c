#include "renderclanker.h"

void free_cylinder(cylinder *cyl) {
	if (cyl->root) free(cyl->root);
	if (cyl->direction) free(cyl->direction);
	if (cyl->color) free(cyl->color);
	free(cyl);
}

cylinder *parse_cylinder(char **tokens) {
	cylinder *cyl;

	cyl = malloc(sizeof(cylinder));
	if (!cyl) {
		return (perror("Failed to allocate memory for a cylinder"), NULL);
	}

	cyl->root = fill_vector(tokens[1]);
	cyl->direction = fill_direction(tokens[2]);
	cyl->radius = ft_atod(tokens[3]) / 2;
	cyl->height = ft_atod(tokens[4]);
	cyl->color = fill_color(tokens[5]);

	if (!cyl->root || !cyl->direction || !cyl->radius || !cyl->height || !cyl->color) {
		free_cylinder(cyl);
		return (perror("Incorrect cylinder definition in .rt file"), NULL);
	}	

	return cyl;
}

bool add_cylinder(composition *comp, char *line) {
	char    **tokens;
	object  *new_obj;
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for cylinder definition in .rt file"), false);
	}
	if (token_count(tokens) != 6 || !check_token(tokens[0], "cy")) {
		free_tokens(tokens);
		return (perror("Incorrect cylinder definition in .rt file"), false);
	}
	
	// Create new object node
	new_obj = malloc(sizeof(object));
	if (!new_obj) {
		free_tokens(tokens);
		return (perror("Memory allocation failed"), false);
	}

	new_obj->type = CYLINDER;
	new_obj->data = parse_cylinder(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	// Check if parse_cylinder failed
	if (!new_obj->data) {
		free(new_obj);
		return (perror("Failed to parse cylinder"), false);
	}
	
	add_object_to_list(comp, new_obj);
	return (true);
}
