/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_array.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/07 16:13:22 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/07 16:19:19 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin_array(char **strings, int count, const char *separator)
{
    size_t  total_len;
    size_t  sep_len;
    char    *result;
    int     i;
    int     j;
    int     k;

    if (!strings || count <= 0)
        return (NULL);
    total_len = 0;
    sep_len = separator ? ft_strlen(separator) : 0;
    i = 0;
    while (i < count)
    {
        if (strings[i])
            total_len += ft_strlen(strings[i]);
        if (i < count - 1 && separator)
            total_len += sep_len;
        i++;
    }
    result = malloc(total_len + 1);
    if (!result)
        return (NULL);
    k = 0;
    i = 0;
    while (i < count)
    {
        j = 0;
        if (strings[i])
        {
            while (strings[i][j])
                result[k++] = strings[i][j++];
        }
        if (i < count - 1 && separator)
        {
            j = 0;
            while (separator[j])
                result[k++] = separator[j++];
        }
        i++;
    }
    result[k] = '\0';
    return (result);
}