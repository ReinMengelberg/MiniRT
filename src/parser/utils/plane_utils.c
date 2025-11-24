/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:18:53 by theyn             #+#    #+#             */
/*   Updated: 2025/11/24 13:23:04 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_plane(t_plane *pl)
{
	if (!pl)
		return ;
	if (pl->root)
		free(pl->root);
	if (pl->direction)
		free(pl->direction);
	if (pl->color)
		free(pl->color);
	free(pl);
}
