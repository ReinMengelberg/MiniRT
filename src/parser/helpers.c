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