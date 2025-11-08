#ifndef RENDERCLANKER_H
#   define RENDERCLANKER_H

#include "libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "fcntl.h"

// STRUCTS
#include "vector.h"
#include "composition.h"
#include "image.h"

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

bool		is_valid_int(char *str);
int			token_count(char **tokens);
bool		check_token(char *token, char *expected);
void		free_tokens(char **tokens);
bool		is_valid_float(char *str);
double		ft_atod(char *str);
float		ft_atof(char *str);




#endif