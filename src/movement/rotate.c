/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:39 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 12:32:56 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	rotate_camera_y(t_composition *comp, float angle) {
	t_vector	*dir = comp->camera->direction;
	float	cos_a = cos(angle);
	float	sin_a = sin(angle);
	float	new_x, new_z;
	
	new_x = dir->x * cos_a - dir->z * sin_a;
	new_z = dir->x * sin_a + dir->z * cos_a;
	
	dir->x = new_x;
	dir->z = new_z;
	
	// Normalize
	float len = sqrt(dir->x * dir->x + dir->y * dir->y + dir->z * dir->z);
	dir->x /= len;
	dir->y /= len;
	dir->z /= len;
	
	// Recalculate viewport with new camera direction
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);  // Removed &
}

void	rotate_camera_x(t_composition *comp, float angle) {
	t_vector	*dir = comp->camera->direction;
	float	cos_a = cos(angle);
	float	sin_a = sin(angle);
	float	new_y, new_z;
	
	new_y = dir->y * cos_a - dir->z * sin_a;
	new_z = dir->y * sin_a + dir->z * cos_a;
	
	dir->y = new_y;
	dir->z = new_z;
	
	// Normalize
	float len = sqrt(dir->x * dir->x + dir->y * dir->y + dir->z * dir->z);
	dir->x /= len;
	dir->y /= len;
	dir->z /= len;
	
	// Recalculate viewport with new camera direction
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);  // Removed &
}
