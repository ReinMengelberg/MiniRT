/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 14:15:06 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/08 14:20:57 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_viewport	*create_viewport(camera *cam, int width, int height)
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
    right = normalize(cross(*cam->direction, world_up));
    up = normalize(cross(right, *cam->direction));
    
    // Calculate viewport vectors (scaled by dimensions)
    vp->hvec = scalar_multiply(right, vp->width);
    vp->vvec = scalar_multiply(up, -vp->height);
    
    // Calculate pixel deltas
    vp->hpdelta = scalar_multiply(vp->hvec, 1.0 / width);
    vp->vpdelta = scalar_multiply(vp->vvec, 1.0 / height);
    
    // Calculate viewport upper left corner
    vp->ptl = add(*cam->root, 
        scalar_multiply(normalize(*cam->direction), focal_length));
    vp->ptl = subtract(vp->ptl, scalar_multiply(vp->hvec, 0.5));
    vp->ptl = subtract(vp->ptl, scalar_multiply(vp->vvec, 0.5));
    
    // Calculate pixel (0,0) center location
    vp->p00 = add(vp->ptl,
        scalar_multiply(add(vp->hpdelta, vp->vpdelta), 0.5));
    
    return (vp);
}

void	free_viewport(t_viewport *vp)
{
    if (vp)
        free(vp);
}