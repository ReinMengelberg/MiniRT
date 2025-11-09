#ifndef IMAGE_H
#define IMAGE_H

#include "renderclanker.h"
#include "vector.h"

typedef struct s_image {
	void    *img_ptr;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}   t_image;

typedef struct s_hit
{
	vector	*loc;		 // The 3D point where ray hit the object
	vector	*normal;     // Surface normal at hit point (for lighting)
	double	t;           // Distance along ray to hit point
	otype	type;
	void	*object;     // Pointer to the object that was hit
}   t_hit;


typedef struct s_ray {
	vector root;
	vector direction;
} t_ray;

typedef struct mlx_data {
	void		*mlx;
	void		*win;
	composition	*comp;
	t_image		*img;
}	mlx_data;

typedef struct s_thread_data{
	t_image		*img;
	composition	*comp;
	int			start_y;
	int			end_y;
}	t_thread_data;

#endif