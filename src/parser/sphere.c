#include "renderclanker.h"

bool add_sphere(composition *comp, char *line)
{
	char	**tokens;
	object	*new_obj;
	object	*current;

	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for sphere definition in .rt file"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "sp")) {
		free_tokens(tokens);
		return (perror("Incorrect sphere definition in .rt file"), false);
	}
	new_obj = malloc(sizeof(object));
	if (!new_obj) {
		free_tokens(tokens);
		return (perror("Memory allocation failed"), false);
	}
	new_obj->type = SPHERE;
	new_obj->data = parse_sphere(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	if (!new_obj->data) {
		free(new_obj);
		return (perror("Failed to parse sphere"), false);
	}
	add_object_to_list(comp, new_obj);
	return (true);
}

sphere *parse_sphere(char **tokens)
{
	sphere	*sphere;

	sphere = malloc(sizeof(sphere));
	if (!sphere) {
		return (perror("Failed ot allocate memory for a sphere"), NULL);
	}
	sphere->root = fill_vector(tokens[1]);
	sphere->radius = atod(tokens[2]) / 2;
	sphere->color = fill_color(tokens[5]);

	if (!sphere->root || !sphere->radius || !sphere->color) {
		free_sphere(sphere);
		return (perror("Incorrect sphere definition in .rt file"), NULL);
	}
	return sphere;
}

void	free_sphere(sphere *sphere) {
	if (sphere->root) free(sphere->root);
	if (sphere->color) free(sphere->color);
	free(sphere);
}
