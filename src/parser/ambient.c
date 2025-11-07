#include "renderclanker.h"

void free_ambient(ambient *amb) {
	if (!amb)
		return;
	if (amb->color) free(amb->color);
	free(amb);
}

ambient *parse_ambient(char **tokens) {
	ambient *amb;

	amb = malloc(sizeof(ambient));
	if (!amb) {
		return (dprintf(2, "Error: Failed to allocate memory for a ambient\n"), NULL);
	}
	
	if (!is_valid_float(tokens[1])) goto error;
	amb->intensity = ft_atof(tokens[1]);
	if (amb->intensity > 1 || amb->intensity < 0) goto error;
	
	amb->color = fill_color(tokens[2]);
	if (!amb->color) goto error;


	return amb;

error:
	free_ambient(amb);
	return (dprintf(2, "Error: Incorrect ambient definition in .rt file\n"), NULL);
}

bool add_ambient(composition *comp, char *line) {
	char    **tokens;

	if (comp->ambient != NULL) {
		return (dprintf(2, "Error: Multiple ambient definitions in .rt file\n"), false);
	}
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (dprintf(2, "Error: Failed to split tokens for ambient definition in .rt file\n"), false);
	}
	if (token_count(tokens) != 3 || !check_token(tokens[0], "A")) {
		free_tokens(tokens);
		return (dprintf(2, "Error: Incorrect ambient definition in .rt file\n"), false);
	}
	
	comp->ambient = parse_ambient(tokens);
	free_tokens(tokens);
	if (!comp->ambient) {
		return false;
	}
	return (true);
}