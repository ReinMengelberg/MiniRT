/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fast.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:22:20 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 13:13:58 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	*render_thread(void *arg)
{
	t_thread_data	*data;
	int				x;
	int				y;
	t_color			color;
	t_ray			ray;

	data = (t_thread_data *)arg;
	y = data->start_y;
	while (y < data->end_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = create_ray(data->comp->camera, data->comp->viewport, x, y);
			color = trace_ray(ray, data->comp);
			put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

static void	setup_thread_data(t_thread_data *data, t_image *img,
		t_composition *comp, int i)
{
	int	rows_per_thread;

	rows_per_thread = HEIGHT / NUM_THREADS;
	data[i].img = img;
	data[i].comp = comp;
	data[i].start_y = i * rows_per_thread;
	if (i == NUM_THREADS - 1)
		data[i].end_y = HEIGHT;
	else
		data[i].end_y = (i + 1) * rows_per_thread;
}

static void	launch_threads(pthread_t *threads, t_thread_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads[i], NULL, render_thread, &data[i]);
		i++;
	}
}

t_image	*render_composition(void *mlx, t_composition *comp, t_image *ex_img)
{
	t_image			*img;
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;

	img = init_image(mlx, ex_img);
	if (!img)
		return (NULL);
	i = 0;
	while (i < NUM_THREADS)
	{
		setup_thread_data(thread_data, img, comp, i);
		i++;
	}
	launch_threads(threads, thread_data);
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (img);
}

void	rerender_scene(t_mlx_data *data)
{
	data->img = render_composition(data->mlx, data->comp, data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
}
