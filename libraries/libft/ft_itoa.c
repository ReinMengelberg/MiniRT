/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:09:35 by theyn             #+#    #+#             */
/*   Updated: 2025/02/13 12:27:29 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	string_length(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = string_length(n);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		length--;
		result[length] = absolute(n % 10) + '0';
		n /= 10;
	}
	return (result);
}
