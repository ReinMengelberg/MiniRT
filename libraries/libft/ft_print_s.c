/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_s.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 15:02:54 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:25:57 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_s(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (ft_print_s("(null)"));
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (i);
}
