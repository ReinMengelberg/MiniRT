/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   composition.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:19:47 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 12:27:00 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSITION_H
# define COMPOSITION_H

# include "vector.h"

// Forward declarations for self-referencing structs
typedef struct s_light	t_light;
typedef struct s_object	t_object;

// Define enum first (needed by object)
typedef enum e_otype
{
	SPHERE,
	CYLINDER,
	PLANE
}						t_otype;

// Define color first (used by many structs)
typedef struct s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

// Define camera (used by composition)
typedef struct s_camera
{
	t_vector			*root;
	t_vector			*direction;
	int					fov;
	float				focal;
}						t_camera;

typedef struct s_viewport
{
	double				height;
	double				width;
	t_vector			hvec;		// horizontal vector
	t_vector			vvec;		// vertical vector
	t_vector			hpdelta;	// horizontal pixel delta
	t_vector			vpdelta;	// vertical pixel delta
	t_vector			ptl;		// pixel at top left corner
	t_vector			p00;		// pixel at 0,0 coords
}						t_viewport;

// Define ambient (used by composition)
typedef struct s_ambient
{
	float				intensity;
	t_color				*color;
}						t_ambient;

// Define light (used by composition)
struct					s_light
{
	t_light				*next;
	t_light				*prev;
	t_vector			*root;
	float				brightness;
	t_color				*color;
};

// Define object (used by composition)
struct					s_object
{
	t_object			*next;
	t_object			*prev;
	t_otype				type;
	void				*data;
};

// Define shape structs
typedef struct s_sphere
{
	t_vector			*root;
	double				radius;
	t_color				*color;
}						t_sphere;

typedef struct s_cylinder
{
	t_vector			*root;
	t_vector			*direction;
	double				radius;
	double				height;
	t_color				*color;
}						t_cylinder;

typedef struct s_cylinder_calc
{
	t_vector			dir_proj;
	t_vector			oc_proj;
	double				a;
	double				b;
	double				c;
}						t_cylinder_calc;

typedef struct s_plane
{
	t_vector			*root;
	t_vector			*direction;
	t_color				*color;
}						t_plane;

// Define composition last (depends on all above types)
typedef struct s_composition
{
	t_camera			*camera;
	t_ambient			*ambient;
	t_object			*objects;
	t_light				*lights;
	t_viewport			*viewport;
}						t_composition;

#endif