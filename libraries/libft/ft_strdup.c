/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:17:14 by theyn             #+#    #+#             */
/*   Updated: 2024/10/20 12:37:58 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*duplicate;	

	i = 0;
	length = 0;
	while (s[length] != '\0')
		length++;
	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (i < length)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
