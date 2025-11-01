/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 18:05:47 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/10/13 15:34:18 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		x;
	const unsigned char	*ptr_s;

	x = c;
	ptr_s = s;
	while (n > 0 && *ptr_s != x)
	{
		ptr_s++;
		n--;
	}
	if (n > 0)
		return ((void *)ptr_s);
	return (NULL);
}
