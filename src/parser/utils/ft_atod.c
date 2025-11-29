/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:00:40 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 15:24:24 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	parse_decimal(char *str, int i, double *result)
{
	double	fraction;

	i++;
	fraction = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result += (str[i] - '0') * fraction;
		fraction *= 0.1;
		i++;
	}
}

double	ft_atod(char *str)
{
	double	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	result = 0.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		parse_decimal(str, i, &result);
	return (result * sign);
}
