/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_array.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/07 16:13:22 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 12:36:00 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_length(char **strings, int count, size_t sep_len)
{
	size_t	total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (i < count)
	{
		if (strings[i])
			total_len += ft_strlen(strings[i]);
		if (i < count - 1 && sep_len > 0)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

static void	copy_string(char *result, char *src, int *k)
{
	int	j;

	j = 0;
	while (src[j])
	{
		result[*k] = src[j];
		(*k)++;
		j++;
	}
}

static void	copy_separator(char *result, const char *sep, int *k)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		result[*k] = sep[j];
		(*k)++;
		j++;
	}
}

static void	join_strings(char **strings, int count, char *result, char *sep)
{
	int	i;
	int	k;

	k = 0;
	i = -1;
	while (++i < count)
	{
		if (strings[i])
			copy_string(result, strings[i], &k);
		if (i < count - 1 && sep)
			copy_separator(result, sep, &k);
	}
	result[k] = '\0';
}

char	*ft_strjoin_array(char **strings, int count, const char *separator)
{
	size_t	total_len;
	size_t	sep_len;
	char	*result;

	if (!strings || count <= 0)
		return (NULL);
	sep_len = 0;
	if (separator)
		sep_len = ft_strlen(separator);
	total_len = calc_length(strings, count, sep_len);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	join_strings(strings, count, result, (char *)separator);
	return (result);
}
