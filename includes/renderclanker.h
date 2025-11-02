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
vector	*fill_vector(char *token);
vector	*fill_direction(char *token);
color	*fill_color(char *token);
void	add_object_to_list(composition *comp, object *new_obj);
void	free_object_data(object *obj);
void	free_all_objects(object *objects);

int		token_count(char **tokens);
bool	check_token(char *token, char *expected);
void	free_tokens(char **tokens);
bool	is_valid_number(char *str);
double	ft_atod(char *str);



#endif