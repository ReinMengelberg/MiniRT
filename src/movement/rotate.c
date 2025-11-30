/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 15:01:39 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/30 12:34:12 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

#define KEY_LEFT 65363
#define KEY_RIGHT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364
#define ROTATE_STEP 0.1

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

static t_vector	calc_new_direction(t_vector *dir, t_vector right, float angle)
{
	t_vector	new_dir;
	float		cos_a;
	float		sin_a;
	float		dot;

	cos_a = cos(angle);
	sin_a = sin(angle);
	dot = right.x * dir->x + right.y * dir->y + right.z * dir->z;
	new_dir.x = dir->x * cos_a + (right.y * dir->z - right.z * dir->y) * sin_a
		+ right.x * dot * (1 - cos_a);
	new_dir.y = dir->y * cos_a + (right.z * dir->x - right.x * dir->z) * sin_a
		+ right.y * dot * (1 - cos_a);
	new_dir.z = dir->z * cos_a + (right.x * dir->y - right.y * dir->x) * sin_a
		+ right.z * dot * (1 - cos_a);
	return (new_dir);
}

static t_vector	get_right_vector(t_vector *dir)
{
	t_vector	up;
	t_vector	right;

	up = (t_vector){0, 1, 0};
	right = vcross(up, *dir);
	vnormalize(right);
	return (right);
}

void	rotate_camera_x(t_composition *comp, float angle)
{
	t_vector	*dir;
	t_vector	right;
	t_vector	new_dir;

	dir = comp->camera->direction;
	right = get_right_vector(dir);
	new_dir = calc_new_direction(dir, right, angle);
	*dir = new_dir;
	vnormalize(*dir);
	if (comp->viewport)
		free(comp->viewport);
	comp->viewport = calculate_viewport(comp->camera, WIDTH, HEIGHT);
}

void	handle_rotation_keys(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_LEFT)
	{
		rotate_camera_y(data->comp, ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_RIGHT)
	{
		rotate_camera_y(data->comp, -ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_UP)
	{
		rotate_camera_x(data->comp, -ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_DOWN)
	{
		rotate_camera_x(data->comp, ROTATE_STEP);
		rerender_scene(data);
	}
}
