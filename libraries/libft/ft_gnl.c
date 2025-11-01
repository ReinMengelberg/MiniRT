#include "libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

bool contains_nl(char *str) {
	int i = 0;
	while(str[i] != '\0') {
		if (str[i] == '\n')
			return true;
		i++;
	}
	return false;
}

int strlen_nl(char *str) {
	int i = 0;
	while (str[i] != '\n' && str[i] != '\0') {
		i++;
	}
	return (i);
}

void move_buffer(char *buffer) {
	int i = 0;
	int j = strlen_nl(buffer) + 1;

	while(buffer[j] != '\0') {
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}

char *cat_buffer(char *line, char *buffer) {
	int i = 0;
	int j = 0;
	char *result;
	int has_nl = contains_nl(buffer) ? 1 : 0;

	result = malloc(strlen_nl(line) + strlen_nl(buffer) + has_nl + 1);
	if (!result) {
		free(line);
		return NULL;
	}

	while (line[i] != '\0') {
		result[i] = line[i];
		i++;
	}

	while (buffer[j] != '\0' && buffer[j] != '\n') {
		result[i] = buffer[j];
		i++;
		j++;
	}

	if (buffer[j] == '\n') {
		result[i] = '\n';
		i++;
	}

	result[i] = '\0';
	free(line);
	return (result);
}

char *get_next_line(int fd) {
	int bytes_read;
	char *line;
	static bool buffer_has_data = false;
	static char buffer[BUFFER_SIZE + 1];

	line = malloc(1);
	if (!line) return NULL;
	line[0] = '\0';

	while(1) {
		if (buffer_has_data) {
			line = cat_buffer(line, buffer);
			if (!line) return (NULL);
			if (contains_nl(buffer)) {
				move_buffer(buffer);
				return(line);
			}
			buffer_has_data = false;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read <= 0) {
			if (strlen_nl(line) > 0) {
				return (line);
			}
			free(line);
			return(NULL);
		}
		buffer_has_data = true;
	}
}