/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:11:26 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 14:46:06 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_ambient(t_ambient *amb)
{
	if (!amb)
		return ;
	if (amb->color)
		free(amb->color);
	free(amb);
}

t_ambient	*ambient_error(t_ambient *amb, char **tokens)
{
	char	*joined;

	joined = ft_strjoin_array(tokens, 3, " ");
	if (joined)
	{
		printf("Error: Incorrect ambient definition \
			(%s) in .rt file\n", joined);
		free(joined);
	}
	else
	{
		printf("Error: Incorrect ambient definition (unknown) in .rt file\n");
	}
	free_ambient(amb);
	return (NULL);
}

t_ambient	*parse_ambient(char **tokens)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_ambient));
	if (!amb)
	{
		printf("Error: Failed to allocate memory for ambient\n");
		return (NULL);
	}
	if (!is_valid_float(tokens[1]))
		return (ambient_error(amb, tokens));
	amb->intensity = ft_atof(tokens[1]);
	if (amb->intensity < 0 || amb->intensity > 1)
		return (ambient_error(amb, tokens));
	amb->color = fill_color(tokens[2]);
	if (!amb->color)
		return (ambient_error(amb, tokens));
	return (amb);
}

bool	add_ambient(t_composition *comp, char *line)
{
	char	**tokens;

	if (comp->ambient != NULL)
	{
		printf("Error: Multiple ambient definitions in .rt file\n");
		return (false);
	}
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		printf("Error: Failed to split tokens for \
			ambient definition in .rt file\n");
		return (false);
	}
	if (token_count(tokens) != 3 || !check_token(tokens[0], "A"))
	{
		free_tokens(tokens);
		printf("Error: Incorrect ambient definition in .rt file\n");
		return (false);
	}
	comp->ambient = parse_ambient(tokens);
	free_tokens(tokens);
	if (!comp->ambient)
		return (false);
	return (true);
}
