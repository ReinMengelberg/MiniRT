/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creator.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:44:59 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/08 13:56:58 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

t_ray	create_ray(camera *cam, int x, int y)
{
    t_ray	ray;

    (void)cam;
    (void)x;
    (void)y;
    
    // Initialize ray origin at camera position (or zeros if cam is NULL)
    ray.root = (vector){0, 0, 0};
    
    // Set a simple forward direction
    ray.direction = (vector){0, 0, -1};
    
    return (ray);
}

