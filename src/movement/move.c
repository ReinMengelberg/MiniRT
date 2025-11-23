/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:35 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 13:56:12 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	move_camera_forward(t_composition *comp, float distance)
{
	t_vector	*pos;
	t_vector	*dir;

	pos = comp->camera->root;
	dir = comp->camera->direction;
	pos->x += dir->x * distance;
	pos->y += dir->y * distance;
	pos->z += dir->z * distance;
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}

void	move_camera_strafe(t_composition *comp, float distance)
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	world_up;
	t_vector	right;

	pos = comp->camera->root;
	dir = comp->camera->direction;
	world_up.x = 0;
	world_up.y = 1;
	world_up.z = 0;
	right = vnormalize(vcross(*dir, world_up));
	pos->x += right.x * distance;
	pos->y += right.y * distance;
	pos->z += right.z * distance;
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}
