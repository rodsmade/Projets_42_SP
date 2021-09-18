#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()
#include <stdlib.h> // free()

char	*g_file_name = "./only_skin";
FILE	*g_fp;

char	*get_next_line(int fd);

int main()
{
	char	*linha;

	g_fp = fopen(g_file_name, "r");
	
	while((linha = get_next_line(g_fp->_fileno)) != NULL)
	{
		printf(">>> %s", linha);
		free(linha);
	}
	
	fclose(g_fp);
	return (0);
}

// #include "get_next_line.h"
// #include "stdio.h"
// #include "unistd.h"
// # include "fcntl.h"

// int main (void)
// {
//     int fd;
//     char *texticulo;
//     int i;

//     i = 1;
//     fd = open("ole/textos_testes", O_RDONLY);

//     while (i)
//     {
//     texticulo = get_next_line(fd);
//     printf("&%s|",texticulo);
//     if (!texticulo)
//         i = 0;
//     //free(texticulo);
//     texticulo = 0;
//     }
//     close(fd);
// }