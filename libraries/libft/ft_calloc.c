/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:48:54 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/10/13 17:01:43 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	char	*mem;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	mem = malloc(bytes);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, bytes));
}
