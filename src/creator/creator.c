/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creator.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:44:59 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 12:31:25 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_ray	create_ray(t_camera *cam, t_viewport *vp, int x, int y)
{
    t_ray	ray;
    t_vector	pixel_center;
    
    // Calculate the center of the pixel at (x, y)
    // Start at p00 (center of pixel 0,0)
    pixel_center = vp->p00;
    
    // Add x * horizontal pixel delta to move right
    pixel_center = vadd(pixel_center, vscale(vp->hpdelta, (double)x));
    
    // Add y * vertical pixel delta to move down
    pixel_center = vadd(pixel_center, vscale(vp->vpdelta, (double)y));
    
    // Ray origin is the camera position
    ray.root = *cam->root;
    
    // Ray direction is from camera to pixel center (normalized)
    ray.direction = vnormalize(vsub(pixel_center, *cam->root));
    
    return (ray);
}

