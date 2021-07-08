#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

char	*file_name = "./only_skin";
int		BUFFER_SIZE = 15;
FILE	*fp;

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
///////////////////////////////////////////////////////////////////////////////

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

//usando open e read
int main(void)
{
	static char	*read_output;
	char	*one_line;
	int		read_return;

	printf("começou o processamento?????\n");
	one_line = NULL;
	read_output = NULL;
	fp = fopen(file_name, "r");
	printf("\nFile descriptor is: %i\n\n\n\n", fp->_fileno);

	while(((read_return = read(fp->_fileno, read_output, BUFFER_SIZE)) > 0)
			&& !(line_found(read_output)))
	{
		printf("read return: %i\n", read_return);
		read_output[read_return] = '\0';
		// printf("||%s||\n", read_output);
		ft_strjoin(one_line, read_output);
	}
	printf("saiu do loop: %i\n", read_return);
	if(read_return < BUFFER_SIZE && read_return > 0)
		ft_strjoin(one_line, read_output);
	printf("Line read: ||%s||\n", one_line);
	fclose(fp);
	return read_return;
}