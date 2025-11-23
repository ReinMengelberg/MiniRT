/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:39 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:00:31 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	rotate_camera_y(t_composition *comp, float angle)
{
	t_vector	*dir;
	float		cos_a;
	float		sin_a;
	float		new_x;
	float		new_z;

	dir = comp->camera->direction;
	cos_a = cos(angle);
	sin_a = sin(angle);
	new_x = dir->x * cos_a - dir->z * sin_a;
	new_z = dir->x * sin_a + dir->z * cos_a;
	dir->x = new_x;
	dir->z = new_z;
	vnormalize(*dir);
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}

void	rotate_camera_x(t_composition *comp, float angle)
{
	t_vector	*dir;
	float		cos_a;
	float		sin_a;
	float		new_y;
	float		new_z;

	dir = comp->camera->direction;
	cos_a = cos(angle);
	sin_a = sin(angle);
	new_y = dir->y * cos_a - dir->z * sin_a;
	new_z = dir->y * sin_a + dir->z * cos_a;
	dir->y = new_y;
	dir->z = new_z;
	vnormalize(*dir);
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}
