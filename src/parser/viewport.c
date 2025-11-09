/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 14:15:06 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/09 11:04:07 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_viewport(t_viewport *vp)
{
	if (vp)
		free(vp);
}

t_viewport	*calculate_viewport(camera *cam, int width, int height)
{
	t_viewport	*vp;
	vector		world_up;
	vector		right;
	vector		up;
	double		focal_length;
	double		aspect_ratio;

	vp = (t_viewport *)malloc(sizeof(t_viewport));
	if (!vp)
		return (NULL);
	
	// Calculate viewport dimensions based on FOV
	focal_length = 1.0;
	vp->height = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0) * focal_length;
	aspect_ratio = (double)width / (double)height;
	vp->width = vp->height * aspect_ratio;
	
	// Calculate camera basis vectors
	world_up = (vector){0, 1, 0};
	right = vnormalize(vcross(*cam->direction, world_up));
	up = vnormalize(vcross(right, *cam->direction));
	
	// Calculate viewport vectors (scaled by dimensions)
	vp->hvec = vscale(right, vp->width);
	vp->vvec = vscale(up, -vp->height);
	
	// Calculate pixel deltas
	vp->hpdelta = vscale(vp->hvec, 1.0 / width);
	vp->vpdelta = vscale(vp->vvec, 1.0 / height);
	
	// Calculate viewport upper left corner
	vp->ptl = vadd(*cam->root, vscale(vnormalize(*cam->direction), focal_length));
	vp->ptl = vsub(vp->ptl, vscale(vp->hvec, 0.5));
	vp->ptl = vsub(vp->ptl, vscale(vp->vvec, 0.5));
	
	// Calculate pixel (0,0) center location
	vp->p00 = vadd(vp->ptl, vscale(vadd(vp->hpdelta, vp->vpdelta), 0.5));
	
	return (vp);
}