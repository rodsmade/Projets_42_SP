#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// não preciso checar se tem ou se não tem algo no resto. parto da premissa de que tem, e vou dando strjoin.
	static char	*rest;
	char		*buffer;
	char		*line;
	int			chars_read;

	while(chars_read > 0 && !contains_nl(line))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if(chars_read < 0)
			return (free_n_quit(rest, line));
		buffer[chars_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (chars_read > 0)
	{
		line = join_up_to_nl(line, buffer);
		rest = save_past_first_nl(rest, buffer);
		// free sth
		return (line);
	}
	return (NULL);
}