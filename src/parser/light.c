/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:53:33 by theyn             #+#    #+#             */
/*   Updated: 2025/11/23 16:25:29 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

bool	light_error(char **tokens, t_light *light)
{
	char	*joined;

	joined = ft_strjoin_array(tokens, 4, " ");
	if (joined)
	{
		printf("Error: Incorrect light definition (%s) in .rt file\n", joined);
		free(joined);
	}
	else
		printf("Error: Incorrect light definition (unknown) in .rt file\n");
	free_tokens(tokens);
	free_light(light);
	return (false);
}

t_light	*parse_light(char **tokens)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->next = NULL;
	light->prev = NULL;
	light->root = NULL;
	light->color = NULL;
	if (!validate_light_values(light, tokens))
		return (NULL);
	return (light);
}

bool	add_light(t_composition *comp, char *line)
{
	char	**tokens;
	t_light	*light;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error: Failed to split tokens\
			for light definition\n"), false);
	if (token_count(tokens) != 4 || !check_token(tokens[0], "L"))
	{
		free_tokens(tokens);
		return (printf("Error: Incorrect light\
			definition in .rt file\n"), false);
	}
	light = parse_light(tokens);
	if (!light)
		return (light_error(tokens, NULL));
	add_light_to_linked_list(comp, light);
	free_tokens(tokens);
	return (true);
}
