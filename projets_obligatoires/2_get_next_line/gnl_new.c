#include "get_next_line.h"

static int	contains_nl(char *string)
// se string vazio ou se não tiver \n, devolve -1. else, a posição;
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

char	*get_next_line(int fd)
{
	// declara vars
	static char	rest[BUFFER_SIZE] = "";
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			chars_read;
	int			nl_pos;

	// inicializa line
	line = ft_strdup("");

	// trata o resto se tiver
	if(*rest == '\n')
	{
		ft_strlcpy(rest, rest + 1, BUFFER_SIZE - 1);
		return ("\n");
	}
	if((nl_pos = contains_nl(rest)) >= 0)
	{
		ft_strlcpy(buffer, rest, BUFFER_SIZE);
		buffer[nl_pos + 1] = '\0';
		line = ft_strjoin(line, buffer);
		ft_strlcpy(rest, rest + nl_pos + 1, BUFFER_SIZE - nl_pos - 1);
		return (line);
	}
	line = ft_strjoin(line, rest);

	// faz o loop infinito dentro
	while ((chars_read = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		buffer[chars_read] = '\0';
		if(chars_read == 0 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		if(chars_read == 0 && *line)
			return (line);
		if(*buffer == '\n')
		{
			ft_strlcpy(rest, buffer + 1, chars_read - 1);
			return ("\n");
		}
		if((nl_pos = contains_nl(buffer)) >= 0 || chars_read < BUFFER_SIZE)
		{
			if(chars_read == BUFFER_SIZE)
			{
				ft_strlcpy(rest, buffer + nl_pos + 1, chars_read - nl_pos);
				buffer[nl_pos + 1] = '\0';
			}
			line = ft_strjoin(line, buffer);
			return (line);
		}
	}
	return (NULL);
}