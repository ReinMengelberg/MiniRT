#include "renderclanker.h"
#include <mlx.h>

#define WIDTH 800
#define HEIGHT 600

#define KEY_ESC 65307

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

void    put_pixel(t_img *img, int x, int y, int color) {
    char    *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


t_img create_image(void *mlx, composition *comp) {
	
}

int	main(int ac, char **av) {
	int			fd;
	composition	*comp;
	void		*image;
	void		*mlx;

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

	mlx = mlx_init();
	if (!mlx)
		return (dprintf(2, "Error: Failed to init MLX\n"), 1);

	

	free_composition(comp);
	return (0);
}