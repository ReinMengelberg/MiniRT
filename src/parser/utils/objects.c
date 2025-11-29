/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:43:44 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 15:51:44 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static t_vector	*create_vector(char **xyz)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
	{
		free_tokens(xyz);
		return (NULL);
	}
	vec->x = ft_atof(xyz[0]);
	vec->y = ft_atof(xyz[1]);
	vec->z = ft_atof(xyz[2]);
	free_tokens(xyz);
	return (vec);
}

t_vector	*fill_vector(char *token)
{
	char	**xyz;

	xyz = ft_split(token, ',');
	if (!xyz || token_count(xyz) != 3)
	{
		free_tokens(xyz);
		return (NULL);
	}
	if (!is_valid_float(xyz[0]) || !is_valid_float(xyz[1])
		|| !is_valid_float(xyz[2]))
	{
		free_tokens(xyz);
		printf("Error: Failed to parse vector from token %s\n", token);
		return (NULL);
	}
	return (create_vector(xyz));
}

static bool	validate_direction_range(t_vector *vec)
{
	if (vec->x > 1 || vec->x < -1 || vec->y > 1 || vec->y < -1
		|| vec->z > 1 || vec->z < -1)
	{
		free(vec);
		printf("Error: direction vector not in range [-1.0,1.0]\n");
		return (false);
	}
	return (true);
}

t_vector	*fill_direction(char *token)
{
	char		**xyz;
	t_vector	*vec;

	xyz = ft_split(token, ',');
	if (!xyz || token_count(xyz) != 3)
	{
		free_tokens(xyz);
		return (NULL);
	}
	if (!is_valid_float(xyz[0]) || !is_valid_float(xyz[1])
		|| !is_valid_float(xyz[2]))
	{
		free_tokens(xyz);
		printf("Error: Parse direction vector from token %s\n", token);
		return (NULL);
	}
	vec = create_vector(xyz);
	if (!vec)
		return (NULL);
	if (!validate_direction_range(vec))
		return (NULL);
	return (vec);
}

bool	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}
