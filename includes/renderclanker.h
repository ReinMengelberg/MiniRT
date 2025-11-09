#ifndef RENDERCLANKER_H
#   define RENDERCLANKER_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "fcntl.h"
#include "libft.h"
#include <mlx.h>

// STRUCTS
#include "vector.h"
#include "composition.h"
#include "image.h"

#define WIDTH 800
#define HEIGHT 600

#define KEY_ESC 65307

#ifndef M_PI
#   define M_PI 3.14159265358979323846
#endif

/**
 * PARSING
 */

composition	*create_composition(int fd);
bool		add_ambient(composition *comp, char *line);
bool		add_camera(composition *comp, char *line);
bool		add_light(composition *comp, char *line);
bool		add_cylinder(composition *comp, char *line);
bool		add_plane(composition *comp, char *line);
bool		add_sphere(composition *comp, char *line);

t_viewport	*calculate_viewport(camera *cam, int width, int height);
vector		*fill_vector(char *token);
vector		*fill_direction(char *token);
color		*fill_color(char *token);
void		add_object_to_list(composition *comp, object *new_obj);
void		free_object_data(object *obj);
void		free_all_objects(object *objects);
void		free_all_lights(light *lights);
void		free_ambient(ambient *ambient);
void		free_camera(camera *camera);
void		free_composition(composition *comp);
void	    free_viewport(t_viewport *vp);

bool		is_valid_int(char *str);
int			token_count(char **tokens);
bool		check_token(char *token, char *expected);
void		free_tokens(char **tokens);
bool		is_valid_float(char *str);
double		ft_atod(char *str);
float		ft_atof(char *str);

/**
 * IMAGE
 */

t_image		*create_image(void *mlx, composition *comp);

/**
 * CREATOR
 */

t_ray	create_ray(camera *cam, int x, int y);

/**
 * TRACER
 */

color	trace_ray(t_ray ray, composition *comp);

/**
 * MATH
 */

vector vadd(vector a, vector b);
vector vsub(vector a, vector b);
vector vscale(vector v, double scalar);
double vdot(vector a, vector b);
double vmagnitude(vector v);
vector vnormalize(vector v);
vector vcross(vector a, vector b);
double vdistance(vector a, vector b);


#endif