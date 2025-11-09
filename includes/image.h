#ifndef IMAGE_H
#define IMAGE_H

#include "renderclanker.h"
#include "vector.h"


typedef struct s_img {
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

#endif