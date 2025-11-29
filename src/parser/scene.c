/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:14:00 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 14:24:09 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_composition	*load_scene(char *filename)
{
	int				fd;
	t_composition	*comp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Error: Can't open file\n");
		return (NULL);
	}
	comp = create_composition(fd);
	close(fd);
	if (!comp)
	{
		ft_dprintf(2, "Error: Failed to parse scene\n");
		return (NULL);
	}
	return (comp);
}
