/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:54:44 by theyn             #+#    #+#             */
/*   Updated: 2024/10/19 11:32:59 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	i;
	unsigned int	length;

	if (!s || !f)
		return (NULL);
	length = ft_strlen (s);
	new_string = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < length)
	{
		if (s && f)
			new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
