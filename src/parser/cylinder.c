#include "renderclanker.h"

bool add_cylinder(composition *comp, char *line) {
	char	**tokens;
	bool	valid_tokens;

	tokens = ft_split(line, ' ');
	if (token_count(tokens) != 6) {
		free_array(tokens);
		return (perror("Incorrect cylinder definition in .rt file"), false);
	}

	valid_tokens = 
}
