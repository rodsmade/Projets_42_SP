#include "get_next_line.h"
#include <stdio.h> // printf()

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

static int	has_nl(char *string)
{
	int i;

	if (!string)
		return (0);
	i = 0;
	while(string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	read_output[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1] = "";
	char	*line;
	int		chars_read;
	int		nl_pos;

	// inicializo essa run do gnl com uma linha vazia.
	line = malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	*line = '\0';

	// se tiver coisa no resto, boto no retorno.
	if (has_nl(rest))
	{
		
	}

	// faço minha primeira leitura do read (incorporar no loop depois ?)
	chars_read = read(fd, read_output, BUFFER_SIZE);
	read_output[chars_read] = '\0';

	while(!(nl_pos = has_nl(read_output)) && chars_read > 0)
	{
		line = ft_strjoin(line, read_output);
		chars_read = read(fd, read_output, BUFFER_SIZE);
		read_output[chars_read] = '\0';
	}

	// se chegou aqui encontrou nl OU está no fim do arquivo e ñ tem nenhuma nl.
	// de qqr jeito guardo o que tem em read_output nessa variável de resto
	ft_strlcpy(rest, read_output, chars_read);

	// fazer um join da linha com o read_output até o \n
	read_output[nl_pos + 1] = '\0';
	line = ft_strjoin(line, read_output);

	return (line);
}
