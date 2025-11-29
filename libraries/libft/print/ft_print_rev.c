/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_rev.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/03 11:29:50 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:21 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_rev(int fd, char *str)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = str[len - i - 1];
		i++;
	}
	result[len] = '\0';
	i = 0;
	while (result[i] != '\0')
	{
		write(fd, &result[i], 1);
		i++;
	}
	free(result);
	return ((int)i);
}

