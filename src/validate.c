/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:12:43 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 14:24:09 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_dprintf(2, "Error:Usage: ./miniRT <scene.rt>\n");
		return (1);
	}
	if (!ft_strnstr(av[1], ".rt", ft_strlen(av[1])))
	{
		ft_dprintf(2, "Error: File must have .rt extension\n");
		return (1);
	}
	return (0);
}
