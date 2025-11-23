/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:22:20 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 11:45:35 by rmengelb      ########   odam.nl         */
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

void	*render_thread(void *arg) {
	t_thread_data	*data;
	int					x;
	int					y;
	color				color;
	t_ray				ray;
	
	data = (t_thread_data *)arg;
	y = data->start_y;
	while (y < data->end_y) {
		x = 0;
		while (x < WIDTH) {
			ray = create_ray(data->comp->camera, data->comp->viewport, x, y);
			color = trace_ray(ray, data->comp);
			put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

t_image	*render_composition(void *mlx, composition *comp, t_image *existing_img) {
	t_image				*img;
	pthread_t			threads[NUM_THREADS];
	t_thread_data		thread_data[NUM_THREADS];
	int					rows_per_thread;
	int					i;
	
	
	// If we have an existing image, reuse it; otherwise create new
	if (existing_img) {
		img = existing_img;
	} else {
		img = malloc(sizeof(t_image));
		if (!img)
			return (dprintf(2, "Failed to allocate memory for image"), NULL);
		img->img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
		img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, 
									   &img->line_length, &img->endian);
	}
	
	// Split work across threads
	rows_per_thread = HEIGHT / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS) {
		thread_data[i].img = img;
		thread_data[i].comp = comp;
		thread_data[i].start_y = i * rows_per_thread;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ? HEIGHT : (i + 1) * rows_per_thread;
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
		i++;
	}
	
	// Wait for all threads to finish
	i = 0;
	while (i < NUM_THREADS) {
		pthread_join(threads[i], NULL);
		i++;
	}
	
	return (img);
}

void	rerender_scene(mlx_data *data) {
	// Reuse existing image buffer, just update the pixel data
	data->img = render_composition(data->mlx, data->comp, data->img);
	mlx_put_image_to_window(data->mlx, data->win, 
							data->img->img_ptr, 0, 0);
}
