/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:35 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 12:32:56 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	move_camera_forward(t_composition *comp, float distance) {
	t_vector	*pos = comp->camera->root;
	t_vector	*dir = comp->camera->direction;
	
	// Move along the camera's direction vector
	pos->x += dir->x * distance;
	pos->y += dir->y * distance;
	pos->z += dir->z * distance;
	
	// Recalculate viewport with new camera position
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}

void	move_camera_strafe(t_composition *comp, float distance) {
	t_vector	*pos = comp->camera->root;
	t_vector	*dir = comp->camera->direction;
	t_vector	world_up = {0, 1, 0};
	t_vector	right;
	
	// Calculate right vector (perpendicular to direction and world up)
	right = vnormalize(vcross(*dir, world_up));
	
	// Move along the right vector
	pos->x += right.x * distance;
	pos->y += right.y * distance;
	pos->z += right.z * distance;
	
	// Recalculate viewport with new camera position
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}