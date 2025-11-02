#include "renderclanker.h"

void add_light_to_linked_list(composition *comp, light *new_light) {
	light *current;
	
	if (!comp->lights) {
		comp->lights = new_light;
	} else {
		current = comp->lights;
		while (current->next) {
			current = current->next;
		}
		current->next = new_light;
		new_light->prev = current;
	}
}

void free_light(light *light) {
	if (!light)
		return;
	if (light->root) free(light->root);
	if (light->color) free(light->color);
	free(light);
}

void free_all_lights(light *lights) {
	light *current;
	light *next;
	
	current = lights;
	while (current) {
		next = current->next;
		free_light(current);
		current = next;
	}
}

bool add_light(composition *comp, char *line) {
	char    **tokens;
	light   *new_light;
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for light definition in .rt file"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "L")) {
		free_tokens(tokens);
		return (perror("Error: Incorrect light definition in .rt file"), false);
	}
	
	new_light = malloc(sizeof(light));
	if (!new_light) {
		free_tokens(tokens);
		return (perror("Error: Memory allocation failed for light"), false);
	}
	
	new_light->root = fill_vector(tokens[1]);
	if (!new_light->root) goto error;

	if (!is_valid_float(tokens[2])) goto error;
	new_light->brightness = ft_atof(tokens[2]);
	if (new_light->brightness < 0 || new_light->brightness > 1) goto error;

	new_light->color = fill_color(tokens[3]);
	if (!new_light->color) goto error;

	new_light->next = NULL;
	new_light->prev = NULL;
	
	add_light_to_linked_list(comp, new_light);
	free_tokens(tokens);
	
	return (true);

error:
	free_tokens(tokens);
	free_light(new_light);
	return (perror("Error: Incorrect light definition in .rt file"), false);
}

// bool add_light(composition *comp, char *line) {
// 	char    **tokens;
// 	light   *new_light;
	
// 	tokens = ft_split(line, ' ');
// 	if (!tokens) {
// 		return (perror("Error: Failed to split tokens for light definition in .rt file"), false);
// 	}
// 	if (token_count(tokens) != 4 || !check_token(tokens[0], "L")) {
// 		free_tokens(tokens);
// 		return (perror("Error: Incorrect light definition in .rt file"), false);
// 	}
	
// 	// Create new light node
// 	new_light = malloc(sizeof(light));
// 	if (!new_light) {
// 		free_tokens(tokens);
// 		return (perror("Error: Memory allocation failed for light"), false);
// 	}
	
// 	new_light->root = fill_vector(tokens[1]);
// 	new_light->brightness = ft_atof(tokens[2]);
// 	new_light->color = fill_color(tokens[3]);
// 	new_light->next = NULL;
// 	new_light->prev = NULL;
// 	free_tokens(tokens);
	
// 	// Validate light data
// 	if (!new_light->root || !new_light->color || new_light->brightness < 0 || new_light->brightness > 1) {
// 		free_light(new_light);
// 		return (perror("Error: Incorrect light definition in .rt file"), false);
// 	}
	
// 	// Add to linked list
// 	add_light_to_linked_list(comp, new_light);
	
// 	return (true);
// }

