/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_and_write.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/03 11:29:50 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:21 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rev_and_write(char *str)
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
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return ((int)i);
}
