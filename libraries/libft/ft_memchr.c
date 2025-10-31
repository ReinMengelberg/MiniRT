/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:40:20 by theyn             #+#    #+#             */
/*   Updated: 2024/10/19 14:39:19 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	location;
	size_t			i;

	str = (unsigned char *)s;
	location = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == location)
			return (str);
		str++;
		i++;
	}
	return (0);
}
