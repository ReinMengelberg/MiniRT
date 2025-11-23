/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 14:04:45 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:08:11 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	print_camera(t_camera *cam)
{
	if (!cam)
	{
		printf("Camera: NULL\n");
		return ;
	}
	printf("\n=== CAMERA ===\n");
	print_vector("  Position", cam->root);
	print_vector("  Direction", cam->direction);
	printf("  FOV: %d\n", cam->fov);
	printf("  Focal length: %.2f\n", cam->focal);
}

void	print_ambient(t_ambient *amb)
{
	if (!amb)
	{
		printf("\nAmbient: NULL\n");
		return ;
	}
	printf("\n=== AMBIENT LIGHT ===\n");
	printf("  Intensity: %.2f\n", amb->intensity);
	print_color("  Color", amb->color);
}

static void	print_light_node(t_light *curr, int count)
{
	printf("  Light #%d:\n", count);
	print_vector("    Position", curr->root);
	printf("    Brightness: %.2f\n", curr->brightness);
	print_color("    Color", curr->color);
}

void	print_lights(t_light *lights)
{
	int		count;
	t_light	*curr;

	count = 0;
	printf("\n=== LIGHTS ===\n");
	if (!lights)
	{
		printf("  No lights\n");
		return ;
	}
	curr = lights;
	while (curr)
	{
		print_light_node(curr, ++count);
		curr = curr->next;
	}
}

void	print_viewport(t_viewport *vp)
{
	if (!vp)
	{
		printf("\nViewport: NULL\n");
		return ;
	}
	printf("\n=== VIEWPORT ===\n");
	printf("  Dimensions: %.2f x %.2f\n", vp->width, vp->height);
	print_vector("  Horizontal vector", &vp->hvec);
	print_vector("  Vertical vector", &vp->vvec);
	print_vector("  H pixel delta", &vp->hpdelta);
	print_vector("  V pixel delta", &vp->vpdelta);
	print_vector("  Top-left pixel", &vp->ptl);
	print_vector("  Pixel (0,0)", &vp->p00);
}