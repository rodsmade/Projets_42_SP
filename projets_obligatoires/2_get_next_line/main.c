#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()

char	*g_file_name = "./ole/textos_testes";
FILE	*g_fp;

char	*get_next_line(int fd);

int main()
{
	char	*linha;

	g_fp = fopen(g_file_name, "r");
	
	while((linha = get_next_line(g_fp->_fileno)) != NULL)
	{
		printf("linha lida: >>> %s", linha);
	}
	
	fclose(g_fp);
	return (0);
}