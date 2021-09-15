#include "get_next_line.h"
#include <stdio.h> // p rintf()

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
	char	*copy;
	int		chars_read;
	int		nl_pos;

	// inicializo essa run do gnl com uma linha vazia.
	line = malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	*line = '\0';

	// se tiver coisa no resto, boto no retorno.
//	printf("//////////////////////////////////\n");
//	printf(">> rest no inicio: %s\n", rest);
	if (*rest)
	{
		//1 tem nl
//		printf("entrou\n");
		if((nl_pos = has_nl(rest)))
		{
//			printf("entrou mas n devia kkkk\n");
			copy = malloc((nl_pos + 1) * sizeof(char));
			if (copy == NULL)
				return (NULL);
			copy[nl_pos] = '\0';
			ft_strlcpy(copy, rest, nl_pos);
			line = ft_strjoin(line, copy);
			ft_strlcpy(rest, rest + nl_pos + 1, BUFFER_SIZE - nl_pos - 1);
			free(copy);
			return (line);
		}
		// não tem nl

//		printf(">> rest antes do join: %s\n", rest);
//		printf(">> line antes do join: %s\n", line);
		line = ft_strjoin(line, rest);
//		printf(">> line depois do join: %s\n", line);
	}

	// faço minha primeira leitura do read (incorporar no loop depois ?)
	chars_read = read(fd, read_output, BUFFER_SIZE);
	read_output[chars_read] = '\0';

//	printf(">> line antes do loop: %s\n", line);
	while(!(nl_pos = has_nl(read_output)) && chars_read > 0)
	{
		line = ft_strjoin(line, read_output);
		chars_read = read(fd, read_output, BUFFER_SIZE);
		read_output[chars_read] = '\0';
	}

	// se chegou aqui encontrou nl OU está no fim do arquivo e ñ tem nenhuma nl.
	// de qqr jeito guardo o que tem em read_output nessa variável de resto
//	printf(">> read_output: %s\n", read_output);
//	printf(">> nl_pos: %i\n", nl_pos);
//	printf(">> chars_read: %i\n", chars_read);
//	printf(">> read_output + nl_pos + 1: '%c'\n", *(read_output + nl_pos + 1));
//	printf(">> rest antes: %s\n", rest);
	if (chars_read == 0)
		return (NULL);
	ft_strlcpy(rest, read_output + nl_pos + 1, chars_read - nl_pos);
//	printf(">> rest depois: %s\n", rest);

	// fazer um join da linha com o read_output até o \n
	read_output[nl_pos + 1] = '\0';
	line = ft_strjoin(line, read_output);

	return (line);
}
