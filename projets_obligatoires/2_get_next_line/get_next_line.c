#include "get_next_line.h"
#include <stdio.h> // p rintf()

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

static int	has_nl(char *string)
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

// static void	handles_rest(char *string)
// {
// 	// TODO: fazer rs
// }

char	*get_next_line(int fd)
{
	char	read_output[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1] = "";
	char	*line;
	char	*copy;
	int		chars_read;
	int		nl_pos;

	// inicializo toda run do gnl com uma linha vazia.
	line = malloc(sizeof(char));
	if(line == NULL)
		return (NULL);
	*line = '\0';

	// se tiver coisa no resto, boto na linha. se tiver \n, encerra pcsto.
	if(*rest)
	{
		// PRIMEIRO CHAR EH NL
		if(*rest == '\n')
		{
			ft_strlcpy(rest, rest + 1, BUFFER_SIZE - 1);
			return ("\n");
		}
		// TEM NL
		if((nl_pos = has_nl(rest)) >= 0)
		{
			copy = malloc((nl_pos + 1) * sizeof(char));
			if(copy == NULL)
				return (NULL);
			copy[nl_pos] = '\0';
			ft_strlcpy(copy, rest, nl_pos);
			line = ft_strjoin(line, copy);
			ft_strlcpy(rest, rest + nl_pos + 1, BUFFER_SIZE - nl_pos - 1);
			free(copy);
			return (line);
		}
		// NÃO TEM NL
		line = ft_strjoin(line, rest);
	}

	// faço minha primeira leitura do read (incorporar no loop depois ?)
	chars_read = read(fd, read_output, BUFFER_SIZE);
	read_output[chars_read] = '\0';
	
	while(!((nl_pos = has_nl(read_output)) >= 0) && chars_read > 0)
	{
		// PRIMEIRO CHAR É NL
		if(*read_output == '\n')
		{
			line = ft_strjoin(line, "\n");
			ft_strlcpy(rest, read_output + 1, chars_read - 1);
			return (line);
		}
		line = ft_strjoin(line, read_output);
		chars_read = read(fd, read_output, BUFFER_SIZE);
		read_output[chars_read] = '\0';
	}
	// se saiu do loop, OU encontrou nl OU está no fim do arquivo e ñ tem nenhuma nl.

	// reached EOF -- se estiver vazio, isso eh NULL, e se tiver algo, devolve esse algo.
	if(chars_read == 0)
	{
		if (*rest == '\0')
			return (NULL);
		*rest = '\0';
		return (line);
	}

	// PRIMEIRO CHAR É NL
	if(*read_output == '\n')
	{
		line = ft_strjoin(line, "\n");
		ft_strlcpy(rest, read_output + 1, chars_read - 1);
		return (line);
	}

	// ALGUM OUTRO 
	ft_strlcpy(rest, read_output + nl_pos + 1, chars_read - nl_pos);
	read_output[nl_pos + 1] = '\0';
	line = ft_strjoin(line, read_output);
	return (line);
}
