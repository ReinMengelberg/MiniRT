/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:15:06 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/24 17:42:18 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

#include "renderclanker.h"

void	free_viewport(t_viewport *vp)
{
	if (vp)
		free(vp);
}

static void	calculate_camera_basis(t_camera *cam, t_vector *right,
	t_vector *up)
{
	t_vector	world_up;

	world_up = (t_vector){0, 1, 0};
	*right = vnormalize(vcross(*cam->direction, world_up));
	*up = vnormalize(vcross(*right, *cam->direction));
}

static void	calculate_dimensions_and_vectors(t_viewport *vp, t_camera *cam,
	int dims[2])
{
	double		focal_length;
	double		aspect_ratio;
	t_vector	right;
	t_vector	up;

	focal_length = 1.0;
	cam->focal = focal_length;
	vp->height = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0) * focal_length;
	aspect_ratio = (double)dims[0] / (double)dims[1];
	vp->width = vp->height * aspect_ratio;
	calculate_camera_basis(cam, &right, &up);
	vp->hvec = vscale(right, vp->width);
	vp->vvec = vscale(up, -vp->height);
	vp->hpdelta = vscale(vp->hvec, 1.0 / dims[0]);
	vp->vpdelta = vscale(vp->vvec, 1.0 / dims[1]);
}

static void	calculate_viewport_position(t_viewport *vp, t_camera *cam,
	double focal_length)
{
	vp->ptl = vadd(*cam->root, vscale(vnormalize(*cam->direction),
				focal_length));
	vp->ptl = vsub(vp->ptl, vscale(vp->hvec, 0.5));
	vp->ptl = vsub(vp->ptl, vscale(vp->vvec, 0.5));
	vp->p00 = vadd(vp->ptl, vscale(vadd(vp->hpdelta, vp->vpdelta), 0.5));
}

t_viewport	*calculate_viewport(t_camera *cam, int width, int height)
{
	t_viewport	*vp;
	int			dims[2];

	vp = (t_viewport *)malloc(sizeof(t_viewport));
	if (!vp)
	{
		printf("Error: viewport memory allocation\n");
		return (NULL);
	}
	dims[0] = width;
	dims[1] = height;
	calculate_dimensions_and_vectors(vp, cam, dims);
	calculate_viewport_position(vp, cam, 1.0);
	return (vp);
}

// void	free_viewport(t_viewport *vp)
// {
// 	if (vp)
// 		free(vp);
// }

// void	calculate_camera_basis(t_camera *cam, t_vector *right,
// 	t_vector *up)
// {
// 	t_vector	world_up;

// 	world_up = (t_vector){0, 1, 0};
// 	*right = vnormalize(vcross(*cam->direction, world_up));
// 	*up = vnormalize(vcross(*right, *cam->direction));
// }

// void	calculate_viewport_dimensions(t_camera *cam, t_viewport *vp,
// 	int width, int height)
// {
// 	double	focal_length;
// 	double	aspect_ratio;

// 	focal_length = 1.0;
// 	cam->focal = focal_length;
// 	vp->height = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0) * focal_length;
// 	aspect_ratio = (double)width / (double)height;
// 	vp->width = vp->height * aspect_ratio;
// }

// void	calculate_viewport_vectors(t_viewport *vp, t_vector right,
// 	t_vector up, int width, int height)
// {
// 	vp->hvec = vscale(right, vp->width);
// 	vp->vvec = vscale(up, -vp->height);
// 	vp->hpdelta = vscale(vp->hvec, 1.0 / width);
// 	vp->vpdelta = vscale(vp->vvec, 1.0 / height);
// }

// void	calculate_viewport_position(t_viewport *vp, t_camera *cam,
// 	double focal_length)
// {
// 	vp->ptl = vadd(*cam->root, vscale(vnormalize(*cam->direction),
// 				focal_length));
// 	vp->ptl = vsub(vp->ptl, vscale(vp->hvec, 0.5));
// 	vp->ptl = vsub(vp->ptl, vscale(vp->vvec, 0.5));
// 	vp->p00 = vadd(vp->ptl, vscale(vadd(vp->hpdelta, vp->vpdelta), 0.5));
// }

// t_viewport	*calculate_viewport(t_camera *cam, int width, int height)
// {
// 	t_viewport	*vp;
// 	int			dims[2];

// 	vp = (t_viewport *)malloc(sizeof(t_viewport));
// 	if (!vp)
// 	{
// 		printf("Error: viewport memory allocation\n");
// 		return (NULL);
// 	}
// 	calculate_viewport_dimensions(cam, vp, width, height);
// 	calculate_camera_basis(cam, &right, &up);
// 	calculate_viewport_vectors(vp, right, up, width, height);
// 	calculate_viewport_position(vp, cam, 1.0);
// 	return (vp);
// }
