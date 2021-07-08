#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

char	*file_name = "./only_skin";
int		BUFFER_SIZE = 5;
FILE	*fp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;
	int		length_s1;
	int		length_s2;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	joint = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++i])
		joint[i + length_s1] = s2[i];
	joint[length_s1 + length_s2] = '\0';
	return (joint);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int line_found(char *buffer)
{
	int i;

	if (buffer == NULL)
		return (0);
	i = -1;
	while(++i < BUFFER_SIZE && buffer[i])
		if (buffer[i] == '\n')
			return (i);
	return (0); 
}

int get_next_line(int fd, char **line)
{
	static char	*read_output;
	int read_return = 0;
	int found_line;
	//char	*one_line;

	read_output = malloc(1);
	if (read_output == NULL)
		return (-1);
	*read_output = '\0';

	*line = malloc(1);
	if (*line == NULL)
		return (-1);
	**line = '\0';

	found_line = line_found(read_output);
	read_return = read(fd, read_output, BUFFER_SIZE);

	while (read_return > 0 && !found_line)
	{
		if (!found_line)
		{
			// printf(" >>> read return: %i\n", read_return);
			// printf("     found line: %i\n", found_line);
			read_output[read_return] = '\0';
			// printf(" >>> linha lida: ||%s||\n", read_output);
			
			*line = ft_strjoin(*line, read_output);

			read_return = read(fd, read_output, BUFFER_SIZE);
			found_line = line_found(read_output);
		}
	}
	read_output[found_line] = '\0';
	*line = ft_strjoin(*line, read_output);

	// printf("\nsaiu do while, read_return: %i\n", read_return);
	// printf("found line: %i\n", found_line);
	// printf("one_line: ||%s||\n", *line);

	return (read_return);
}

int main(void)
{
	char	**line;
	int		gnl_return;
	int		i = 0;

	line = malloc((211 + 1) * sizeof(*line));
	fp = fopen(file_name, "r");
	printf("\nFile descriptor is: %i\n\n\n\n", fp->_fileno);

	gnl_return = get_next_line(fp->_fileno, line + i);
	while (gnl_return > 0)
	{
		printf("Linha lida: ||%s||\n", line[i]);
		i++;
		gnl_return = get_next_line(fp->_fileno, line + i);
	}

	fclose(fp);
	return (0);
}