/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:01:07 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 15:42:48 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	parse_decimal(char *str, int i, float *result)
{
	float	fraction;

	i++;
	fraction = 0.1f;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result += (str[i] - '0') * fraction;
		fraction *= 0.1f;
		i++;
	}
}

float	ft_atof(char *str)
{
	float	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	result = 0.0f;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0f + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		parse_decimal(str, i, &result);
	return (result * sign);
}
