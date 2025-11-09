/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:21:50 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/09 13:21:10 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

typedef struct mlx_data {
	void		*mlx;
	void		*win;
	composition	*comp;

}	mlx_data;

int	handle_keypress(int keycode, mlx_data *data) {
	if (keycode == KEY_ESC) {
		mlx_destroy_window(data->mlx, data->win);
		free_composition(data->comp);
		exit(0);
	}
	return (0);
}

int	handle_close(mlx_data *data) {
	mlx_destroy_window(data->mlx, data->win);
	free_composition(data->comp);
	exit(0);
	return (0);
}

int	main(int ac, char **av) {
	int			fd;
	composition	*comp;
	t_image		*image;
	mlx_data	data;

	if (ac != 2)
		return (dprintf(2, "Error:Usage: ./miniRT <scene.rt>\n"), 1);
	if (!ft_strnstr(av[1], ".rt", ft_strlen(av[1])))
		return (dprintf(2, "Error: File must have .rt extension\n"), 1);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (dprintf(2, "Error: Can't open file\n"), 1);
	comp = create_composition(fd);
	close(fd);
	if (!comp)
		return (dprintf(2, "Error: Failed to parse scene\n"), 1);
	print_composition(comp);

	data.mlx = mlx_init();
	if (!data.mlx)
		return (dprintf(2, "Error: Failed to init MLX\n"), 1);

	image = create_image(data.mlx, comp);
	data.comp = comp;
	
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MiniRT");
	if (!data.win)
		return (dprintf(2, "Error: Failed to create window\n"), 1);
	
	mlx_put_image_to_window(data.mlx, data.win, image->img_ptr, 0, 0);
	
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_keypress, &data);
	
	mlx_loop(data.mlx);
	
	return (0);
}