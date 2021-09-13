#include "get_next_line.h"
#include <stdio.h>			// printf, fopen, FILE
#include <stdlib.h>			// atoi

int		g_BUFFER_SIZE = 100;
char	*g_file_name = "./ole/only_skin";
FILE	*g_fp;

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

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char) c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (s[i] == (unsigned char) c)
// 		return ((char *)s + i);
// 	return (NULL);
// }

int		find_return(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	// rodou tudo e não achou:
	return (-1);
}

char	*get_next_line(int fd)
/**
 * Return value Read line: correct behavior
 * NULL: nothing else to read or an error occurred
 * 
 *  Important: You should always return the line that has been read followed by a ’\n’
 * unless you have reach end of file and there is no ’\n’.
 **/
{
	static char	*buffer = NULL;
	char		*read_output;
	int			read_return;
	char		*gnl_return;

	// aloca memória pro q vai ser lido
	read_output = malloc((g_BUFFER_SIZE + 1) * sizeof(*read_output));
	if (read_output == NULL)
		return (NULL);
	read_output[g_BUFFER_SIZE] = '\0';

	read_return = read(fd, read_output, g_BUFFER_SIZE);

	while (find_return(buffer) < 0
		&& find_return(read_output) < 0
		&& read_return > 0)
	{
		if (find_return(read_output) >= 0
			|| read_return > 0)
		{
			ft_strlcat()
			break ;
		}
		ft_strlcat(buffer, read_output, g_BUFFER_SIZE);
	}


	// 
	if (read(fd, read_output, g_BUFFER_SIZE) == 0)
		return (NULL);
	return (gnl_return);
}

int main(void)
{
	char	*linha;

	// if (argc != 2)
	// {
	// 	printf("Esqueceu o g_BUFFER_SIZE !\n");
	// 	return (-1);
	// }

	// g_BUFFER_SIZE = atoi(argv[1]);
	// printf("g_BUFFER_SIZE: %i\n", g_BUFFER_SIZE);

	g_fp = fopen(g_file_name, "r");

	if (!(linha = malloc((g_BUFFER_SIZE + 1) * sizeof(*linha))))
		return (-1);

	linha = get_next_line(g_fp->_fileno);
	while (linha != NULL)
	{
		printf("Linha lida: >>%s<<\n", linha);
		linha = get_next_line(g_fp->_fileno);
	}

	return (0);
}