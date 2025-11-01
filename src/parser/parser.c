#include "renderclanker.h"

composition *create_composition(int fd) {
	composition	*comp;
	char		*line;
	comp = malloc(sizeof(composition));

	line = get_next_line(fd);
	while (line) {
		
	}
}