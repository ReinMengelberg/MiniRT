#include "renderclanker.h"

int token_count(char **tokens)
{
	int count;
	
	if (!tokens)
		return (false);
	count = 0;
	while (tokens[count])
		count++;
	return count;
}

bool check_token(char *token, char *expected)
{
	int i;
	
	if (!token || !expected)
		return (false);
	
	i = 0;
	while (token[i] && expected[i])
	{
		if (token[i] != expected[i])
			return (false);
		i++;
	}
	return (token[i] == '\0' && expected[i] == '\0');
}

void free_tokens(char **tokens)
{
	int i;
	
	if (!tokens)
		return;
	
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

bool is_valid_float(char *str)
{
    int		i;
    bool	has_digit;
    bool	has_dot;

    if (!str || !*str)
        return (false);
    i = 0;
    has_digit = false;
    has_dot = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (has_dot)
                return (false);
            has_dot = true;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            has_digit = true;
        else
            return (false);
        i++;
    }
    return (has_digit);
}

double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	result = 0.0;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.') {
		i++;
		fraction = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * fraction;
			fraction *= 0.1;
			i++;
		}
	}
	return (result * sign);
}

float	ft_atof(char *str)
{
	float	result;
	float	fraction;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	result = 0.0f;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10.0f + (str[i] - '0');
		i++;
	}
	if (str[i] == '.') {
		i++;
		fraction = 0.1f;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * fraction;
			fraction *= 0.1f;
			i++;
		}
	}
	return (result * sign);
}