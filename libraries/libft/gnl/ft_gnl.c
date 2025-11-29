/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gnl.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:37:25 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 12:43:08 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

void	move_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = strlen_nl(buffer) + 1;
	while (buffer[j] != '\0')
	{
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}

char	*cat_buffer(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*result;

	result = allocate_result(line, buffer);
	if (!result)
		return (free(line), NULL);
	i = 0;
	while (line[i] != '\0')
	{
		result[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0' && buffer[j] != '\n')
		result[i++] = buffer[j++];
	if (buffer[j] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	free(line);
	return (result);
}

int	process_buffer(char **line, char *buffer, int *has_data)
{
	*line = cat_buffer(*line, buffer);
	if (!(*line))
		return (0);
	if (contains_nl(buffer))
	{
		move_buffer(buffer);
		return (1);
	}
	*has_data = 0;
	return (-1);
}

char	*handle_read(char *line, int bytes_read)
{
	if (bytes_read <= 0)
	{
		if (strlen_nl(line) > 0)
			return (line);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static int	buffer_has_data;
	static char	buffer[BUFFER_SIZE + 1];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (1)
	{
		if (buffer_has_data && process_buffer(&line, buffer,
				&buffer_has_data) != -1)
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			return (handle_read(line, bytes_read));
		buffer_has_data = 1;
	}
}
