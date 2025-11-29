/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gnl_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:41:07 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 12:43:18 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contains_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*allocate_result(char *line, char *buffer)
{
	char	*result;
	int		has_nl;
	int		total_len;

	if (contains_nl(buffer))
		has_nl = 1;
	else
		has_nl = 0;
	total_len = strlen_nl(line) + strlen_nl(buffer) + has_nl + 1;
	result = malloc(total_len);
	return (result);
}
