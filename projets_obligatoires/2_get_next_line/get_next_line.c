#include <unistd.h> // read()
#include <stdlib.h> // malloc()

char	*get_next_line(int fd, int try)
{
	char	*read_output;

	read_output = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_output == NULL)
		return (NULL);
	if (try > 3)
		return (NULL);
	read(fd, read_output, BUFFER_SIZE);
	read_output[BUFFER_SIZE] = '\0';
	return (read_output);
}
