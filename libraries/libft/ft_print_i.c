/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_i.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 15:42:30 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:25:44 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_i(int integer)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_itoa(integer);
	if (temp == NULL)
		return (0);
	while (temp[i] != '\0')
	{
		write (1, &temp[i], 1);
		i++;
	}
	free(temp);
	return (i);
}
