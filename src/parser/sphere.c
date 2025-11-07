#include "renderclanker.h"

void	free_sphere(sphere *sph) {
	if (sph->root) free(sph->root);
	if (sph->color) free(sph->color);
	free(sph);
}

sphere *parse_sphere(char **tokens)
{
	sphere	*sph;

	sph = malloc(sizeof(sphere));
	if (!sph) {
		return (dprintf(2, "Failed to allocate memory for a sphere\n"), NULL);
	}

	sph->root = fill_vector(tokens[1]);
	if (!sph->root) goto error;

	if (!is_valid_float(tokens[2])) goto error;
	sph->radius = ft_atod(tokens[2]) / 2;

	sph->color = fill_color(tokens[3]);
	if (!sph->color) goto error;

	return sph;

error:
	free_sphere(sph);
	char *joined = ft_strjoin_array(tokens, 4, " ");
	dprintf(2, "Error: Incorrect sphere definition (%s) in .rt file\n", joined ? joined : "unknown");
	free(joined);
	return (NULL);
}

bool add_sphere(composition *comp, char *line)
{
	char	**tokens;
	object	*new_obj;

	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (dprintf(2, "Error: Failed to split tokens for sphere definition in .rt file\n"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "sp")) {
		char *joined = ft_strjoin_array(tokens, token_count(tokens), " ");
		dprintf(2, "Error: Incorrect sphere definition (%s) in .rt file\n", joined ? joined : "unknown");
		free(joined);
		free_tokens(tokens);
		return (false);
	}
	new_obj = malloc(sizeof(object));
	if (!new_obj) {
		free_tokens(tokens);
		return (dprintf(2, "Memory allocation failed\n"), false);
	}
	new_obj->type = SPHERE;
	new_obj->data = parse_sphere(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_tokens(tokens);

	if (!new_obj->data) {
		free(new_obj);
		return (dprintf(2, "Failed to parse sphere\n"), false);
	}
	add_object_to_list(comp, new_obj);
	return (true);
}