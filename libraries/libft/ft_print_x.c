/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_x.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 18:07:48 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:06 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(unsigned int x)
{
	const char		*hex_digits;
	char			temp[19];
	int				i;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (x == 0)
		temp[i++] = '0';
	while (x > 0)
	{
		temp[i++] = hex_digits[x % 16];
		x /= 16;
	}
	temp[i] = '\0';
	return (ft_rev_and_write(temp));
}
