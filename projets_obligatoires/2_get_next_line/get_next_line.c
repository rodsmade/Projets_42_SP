#include "get_next_line.h"

static int has_return_char(char *string)
{
	int i;

	i = 0;
	while(string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static void saves_the_rest(char *string)
{
	// TODO
}

char *get_next_line(int fd)
{
	char		*retorno_gnl;	// acho q vou precisar de um malloc 
	char		*read_output[BUFFER_SIZE + 1];
	int			read_return;
	int			wheres_the_return;
	static char	*rest = NULL;

	if(has_return_char(rest))
	{
		// TODO fim 1 
	}
	while(read_return = read(fd, read_output, BUFFER_SIZE) > 0)
	{
		read_output[read_return] = '\0';
		if (wheres_the_return = has_return_char(read_output))
		{
			ft_strlcat(retorno_gnl, read_output, wheres_the_return + 1);
			saves_the_rest(read_output[wheres_the_return]);
			// Important: You should always return the line that has been read followed by a ’\n’
			// unless you have reached end of file and there is no ’\n’.
			return (retorno_gnl);
		}
		ft_strlcat(retorno_gnl, read_output, BUFFER_SIZE);
	}
	// se saiu do while eh pq atingiu EOF. ainda tem algo a ser lido em read_output?
	// EOF: read_return == 0
	if (read_return != 0)
	// deu algum ruim
		return (NULL);
	if (wheres_the_return = has_return_char(read_output))
	{
		ft_strlcat(retorno_gnl, read_output, wheres_the_return);
		saves_the_rest(read_output[wheres_the_return]);
		return (retorno_gnl);
	}

}