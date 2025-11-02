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

// Free a 2D array (array of strings)
void free_array(char **tokens)
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

bool	is_valid_number(char *str)
{
	int	i = 0;
	int	dot_count = 0;

	if (!str || str[0] == '\0')
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		return false;
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return false;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return false;
		i++;
	}
	return true;
	
}

// convert ascii to double
double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	int		sign = 1;
	int		i = 0;

	result = 0.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
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