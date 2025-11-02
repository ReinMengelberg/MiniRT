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
		return (perror("Error: Failed to allocate memory for a ambient"), NULL);
	}

	amb->color = fill_color(tokens[1]);
	if (!amb->color) goto error;

	amb->intensity = ft_atof(tokens[2]);
	if (amb->intensity > 1 || amb->intensity < 0) goto error;

	return amb;

error:
	free_ambient(amb);
	return (perror("Error: Incorrect ambient definition in .rt file"), NULL);
}

bool add_ambient(composition *comp, char *line) {
	char    **tokens;

	if (comp->ambient != NULL) {
		return (perror("Error: Multiple ambient definitions in .rt file"), false);
	}
	
	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for ambient definition in .rt file"), false);
	}
	if (token_count(tokens) != 3 || !check_token(tokens[0], "A")) {
		free_tokens(tokens);
		return (perror("Error: Incorrect ambient definition in .rt file"), false);
	}
	
	comp->ambient = parse_ambient(tokens);
	free_tokens(tokens);
	if (!comp->ambient) {
		return false;
	}
	return (true);
}