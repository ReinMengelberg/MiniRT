/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rein <rein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 22:06:06 by rein          #+#    #+#                 */
/*   Updated: 2024/10/13 15:48:23 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*x;

	x = (char *)s;
	while (*x != '\0')
	{
		if (*x == (char)c)
			return (x);
		x++;
	}
	if (c == '\0')
		return (x);
	return (NULL);
}
