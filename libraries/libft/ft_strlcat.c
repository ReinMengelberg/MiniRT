/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:15:05 by theyn             #+#    #+#             */
/*   Updated: 2024/10/20 12:50:18 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	slen = 0;
	i = 0;
	while (dst[dlen] != '\0' && dlen < size)
		dlen++;
	while (src[slen] != '\0')
		slen++;
	if (dlen == size)
		return (size + slen);
	while (src[i] != '\0' && (dlen + i) < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
