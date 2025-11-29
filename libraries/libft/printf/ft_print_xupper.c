/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_xupper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 18:07:43 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 14:19:05 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_xupper(int fd, unsigned int x)
{
	const char		*hex_digits;
	char			temp[19];
	int				i;

	hex_digits = "0123456789ABCDEF";
	i = 0;
	if (x == 0)
		temp[i++] = '0';
	while (x > 0)
	{
		temp[i++] = hex_digits[x % 16];
		x /= 16;
	}
	temp[i] = '\0';
	return (ft_dprint_rev(fd, temp));
}
