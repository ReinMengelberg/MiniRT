/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:35 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/09 15:10:09 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	move_camera_forward(composition *comp, float distance) {
	vector	*pos = comp->camera->root;
	vector	*dir = comp->camera->direction;
	
	// Move along the camera's direction vector
	pos->x += dir->x * distance;
	pos->y += dir->y * distance;
	pos->z += dir->z * distance;
	
	// Recalculate viewport with new camera position
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}

void	move_camera_strafe(composition *comp, float distance) {
	vector	*pos = comp->camera->root;
	vector	*dir = comp->camera->direction;
	vector	world_up = {0, 1, 0};
	vector	right;
	
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