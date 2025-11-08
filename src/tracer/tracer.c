/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:45:02 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/08 12:54:40 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

color	trace_ray(t_ray ray, composition *comp)
{
    color	gray;

    (void)ray;
    (void)comp;
    
    // Return a gray color (RGB values around 128)
    gray.r = 128;
    gray.g = 128;
    gray.b = 128;
    
    return (gray);
}