/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 18:06:02 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/10/13 15:47:28 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	while (n > 0 && *ptr_s1 == *ptr_s2)
	{
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ptr_s1 - *ptr_s2);
}
