#include "get_next_line.h"

static int	contains_nl(char *string)
// true if return >= 0; false otherwise
{
	int i;

	if(!string)
		return (-1);
	i = 0;
	while(string[i])
	{
		if(string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	*free_n_quit(char *string)
{
	if(string)
		free(string);
	return (NULL);
}

static char	*copy_up_to_nl(char *string)
{
	int	nl_pos;

	nl_pos = 0;
	if(!string || !((nl_pos = contains_nl(string)) >= 0))	
		return (NULL);
	ft_strlcpy(string, string, nl_pos + 2);
	return (string);
}


static char	*save_past_first_nl(char *source)
{
	char	*dest;
	int		nl_pos;
	int		strlen;

	if(!((nl_pos = contains_nl(source)) >= 0))
		return (NULL);
	dest = malloc(((strlen = ft_strlen(source)) - nl_pos) * sizeof(char));
	if(dest == NULL)
		return (NULL);
	dest[strlen - nl_pos - 1] = '\0';
	ft_strlcpy(dest, source + nl_pos + 1, strlen - nl_pos);
	return (dest);
}

char		*get_next_line(int fd)
{
	// não preciso checar se tem ou se não tem algo no resto. parto da premissa de que tem, e vou dando strjoin.
	static char	*rest = "";
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			chars_read;

	line = ft_strdup(rest);
	chars_read = BUFFER_SIZE;
	while(chars_read == BUFFER_SIZE && contains_nl(line) < 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if(chars_read < 0)
			return (free_n_quit(line));
		buffer[chars_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (chars_read == 0)
		return (NULL);
	if (chars_read == BUFFER_SIZE)
	{
		rest = save_past_first_nl(line);
		line = copy_up_to_nl(line);
	}
	return (line);
}
