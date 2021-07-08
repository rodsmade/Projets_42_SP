#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

///////////////////////////////////////////////////////////////////////////////////////
int		BUFFER_SIZE = 10;
FILE	*fptr;
char	*file_path = "./only_skin";

size_t	ft_strlen(const char *s)
{
	int	qtd_caracteres;

	qtd_caracteres = 0;
	while (*s)
	{
		qtd_caracteres++;
		s++;
	}
	return (qtd_caracteres);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	i = 0;
	if (dstlen < size)
	{
		while ((i + dstlen) < (size - 1) && src[i])
		{
			dst[i + dstlen] = src[i];
				i++;
		}
		dst[i + dstlen] = '\0';
	}
	return (dstlen + srclen);
}
///////////////////////////////////////////////////////////////////////////////

int line_found(char *buffer)
{
	int i;

	i = -1;
	while(++i < BUFFER_SIZE)
		if (buffer[i] == '\n')
			return (i);
	return (0); 
}

int	get_next_line(const int fd, char **line)
/**
 * retornos possiveis:
 * 	0:> EOF has been reached
 * 	1:> a line has been read
 * 	-1:> an error occurred
 **/
{
	static char	*checkpoint;	// vai existir por toda a duração do main q chama gnl...
	ssize_t		read_return;
	int			caret;
	// int			BUFFER_SIZE = 5;

	// abre o arquivo que eu quero
	fptr = fopen(file_path, "r");
	printf("File descriptor is: %i\n\n\n\n", fptr->_fileno);
	*line = '\0';
	// args protection
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while((read_return = read(fd, checkpoint, BUFFER_SIZE)) > 0
		&& !(caret = line_found(checkpoint)))
	{
		if (read_return < BUFFER_SIZE)
			checkpoint[read_return] = '\0';
		ft_strlcat(*line, checkpoint, BUFFER_SIZE);
		// SE SIM, copia td até a line break
		// bota um '\0'
		// salva o seu checkpoint. o checkpoint eh um ponteiro
		// encerra a execução
		// SE NÃO, continua lendo até encontrar......
		// printf("read return: %i\n", read_return);
		// if (read_return < BUFFER_SIZE)
		// 	read_o utput[read_return] = '\0';
		// printf("||%s||\n", checkpoint);
	}
	if (read_return < 0)
		return (-1);
	ft_strlcat(*line, checkpoint, caret);
	checkpoint = checkpoint + caret;
	return (0);
}

//////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	char	**line;
	int		gnl_return;

	// eu já sei de antemão quantas linhas existem no arquivo então
	line = malloc((211 + 1) * sizeof(*line));
	if (line == NULL)
		return (-1);
	line[211] = NULL;
	// chama gnl em loop, até dar ruim ou até chegar ao fim do arquivo
	int i = 0;
	while((gnl_return = get_next_line(3, line)) > 0)
	{
		printf("gnl_return: %i\n", gnl_return);
		printf("Line read: ||%s||\n", line[i]);
		i++;
	}
	printf("fim do loop gnl: %i\n", gnl_return);

	// fecha o arquivo e encerra execução
	fclose(fptr);
	return (0);
}
