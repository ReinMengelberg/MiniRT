/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_procent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 14:54:56 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:25:52 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_procent(int fd)
{
	write(fd, "%", 1);
	return (1);
}
