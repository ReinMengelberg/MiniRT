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
int token_count(char **tokens);
void free_array(char **tokens);
bool	is_valid_number(char *str);
double	ft_atod(char *str);
vector	*fill_vector(char *token);
bool check_token(char *token, char *expected);
void add_object_to_list(composition *comp, object *new_obj);


#endif