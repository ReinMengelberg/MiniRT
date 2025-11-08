/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:22:20 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/08 12:52:29 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

int	color_to_hex(color c) {
	return ((c.r << 16) | (c.g << 8) | c.b);
}

void	put_pixel(t_image *img, int x, int y, color c) {
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color_to_hex(c);
}

t_image *create_image(void *mlx, composition *comp) {
	t_image	*img;
	int		x;
	int		y;
	color	color;
	t_ray	ray;
	
	img = malloc(sizeof(t_image));
	if (!img) {
		return (dprintf(2, "Failed to allocate memory for image"), NULL);
	}
	img->img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	y = 0;
	while (y < HEIGHT) {
		x = 0;
		while (x < WIDTH) {
			ray = create_ray(comp->camera, x, y);
			color = trace_ray(ray, comp);
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}