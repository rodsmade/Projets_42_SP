#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// int	 BUFFER_SIZE = 25;
char	*g_file_name = "./ole/textos_testes";
FILE	*g_fp;

char	*get_next_line(int fd);

int main()
{
	char	*line;
	int count = 0;
	// char *read_output;
	// int	read_return;

	// read_output = malloc(1);
	// if (read_output == NULL)
	// 	return (-1);
	// *read_output = '\0';

	g_fp = fopen(g_file_name, "r");
	line = get_next_line(g_fp->_fileno);
	while ((line = get_next_line(g_fp->_fileno)) != NULL)
	{
		printf("Linha %i:\t%s\n", count, line);
		count++;
	}
	printf("\n\n\n fim\n");

	return (0);
}