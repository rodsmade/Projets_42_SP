#include "get_next_line.h"

char	*get_next_line(int fd)
/**
 * Return value Read line: correct behavior
 * NULL: nothing else to read or an error occurred
 **/
{
	char	*content_read;
	char	*line_read;

	content_read = malloc((BUFFER_SIZE + 1) * sizeof(*content_read));
	read(fd, content_read, BUFFER_SIZE);

	return (line_read);
}