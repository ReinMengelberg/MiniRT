#include "renderclanker.h"

vector	*fill_vector(char *token)
{
	char	**xyz;
	int		i = 0;

	xyz = ft_split(token, ',');
	if (!xyz || token_count(xyz) != 3)
	{
		free_array(xyz);
		return NULL;
	}
	while (i < 3)
	{
		if (!is_valid_number(xyz[i]))
		{
			free_array(xyz);
			return NULL;
		}
		i++;
	}
}

color *fill_color(char *token) {

};