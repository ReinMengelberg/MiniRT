#ifndef COMPOSITION_H
#define COMPOSITION_H

#include "vector.h"

// Forward declarations (only for pointers)
typedef struct camera camera;
typedef struct ambient ambient;
typedef struct light light;
typedef struct object object;
typedef struct color color;
typedef enum otype otype;

// Define enum first (needed by object)
typedef enum otype{
	SPHERE,
	CYLINDER,
	PLANE
} otype;

// Define color first (used by many structs)
typedef struct color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
} color;

// Define camera (used by composition)
typedef struct camera {
	vector	*root;
	vector	*direction;
	int		fov;
	float	focal;
} camera;

typedef struct s_viewport {
	double	height;
	double	width;
	vector	hvec; // horizontal vector
	vector	vvec; // vertical vector
	vector	hpdelta; // horizontal pixel delta (space between pixels)
	vector	vpdelta; // vertical pixel delta (space between pixels)
	vector	ptl; // pixel at top left corner
	vector	p00; // pixel at 0,0 coords
} t_viewport;

// Define ambient (used by composition)
typedef struct ambient {
	float	intensity;
	color	*color;
} ambient;

// Define light (used by composition)
typedef struct light {
	light	*next;
	light	*prev;
	vector	*root;
	float	brightness;
	color	*color;
} light;

// Define object (used by composition)
typedef struct object {
	object	*next;
	object	*prev;
	otype	type;
	void	*data;
} object;

// Define shape structs
typedef struct sphere {
	vector	*root;
	double	radius;
	color	*color;
} sphere;

typedef struct cylinder {
	vector	*root;
	vector	*direction;
	double	radius;
	double	height;
	color	*color;
} cylinder;

typedef struct plane {
	vector	*root;
	vector	*direction;
	color	*color;
} plane;



// Define composition last (depends on all above types)
typedef struct composition {
	camera 		*camera;
	ambient		*ambient;
	object		*objects;
	light		*lights;
	t_viewport	*viewport;
} composition;

#endif