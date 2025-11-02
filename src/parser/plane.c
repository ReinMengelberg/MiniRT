#include "renderclanker.h"

bool add_plane(composition *comp, char *line) {
	char	**tokens;
	object	*new_obj;
	object	*current;

	tokens = ft_split(line, ' ');
	if (!tokens) {
		return (perror("Error: Failed to split tokens for plane definition in .rt file"), false);
	}
	if (token_count(tokens) != 4 || !check_token(tokens[0], "pl")) {
		free_array(tokens);
		return (perror("Incorrect cylinder definition in .rt file"), false);
    }

	new_obj = malloc(sizeof(object));
    if (!new_obj) {
        free_array(tokens);
        return (perror("Memory allocation failed"), false);
    }

	new_obj->type = PLANE;
	new_obj->data = parse_plane(tokens);
	new_obj->next = NULL;
	new_obj->prev = NULL;
	free_array(tokens);

	if (!new_obj->data) {
		free(new_obj);
		return (perror("Failed to parse plane"), false);
	}
}