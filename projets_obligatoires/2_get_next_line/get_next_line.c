#include "get_next_line.h"

static int	contains_nl(char *string)
// true if return >= 0; false otherwise
{
	int	i;

	if (!string)
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	*free_n_quit(char *string)
{
	if (string)
		free(string);
	return (NULL);
}

static char	*copy_up_to_nl(char *string)
{
	char	*copy;
	int		nl_pos;

	nl_pos = contains_nl(string);
	if (!string)
		return (NULL);
	if (!(nl_pos >= 0))
		return (string);
	copy = malloc((nl_pos + 2) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy[nl_pos + 1] = '\0';
	ft_strlcpy(copy, string, nl_pos + 2);
	free(string);
	return (copy);
}

static char	*save_past_first_nl(char *source)
{
	char	*dest;
	int		nl_pos;
	int		strlen;

	nl_pos = contains_nl(source);
	if (!(nl_pos >= 0))
		return (NULL);
	dest = malloc(((strlen = ft_strlen(source)) - nl_pos) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[strlen - nl_pos - 1] = '\0';
	ft_strlcpy(dest, source + nl_pos + 1, strlen - nl_pos);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			chars_read;

	if (!rest)
		rest = ft_strdup("");
	line = ft_strdup(rest);
	chars_read = BUFFER_SIZE;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (chars_read == BUFFER_SIZE && contains_nl(line) < 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			free(rest);
			rest = NULL;
			free(buffer);
			return (free_n_quit(line));
		}
		buffer[chars_read] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	if (chars_read == 0)
	{
		free(rest);
		rest = NULL;
		if (line && *line)
			return (line);
		return (free_n_quit(line));
	}
	free(rest);
	rest = save_past_first_nl(line);
	line = copy_up_to_nl(line);
	return (line);
}
