#include <stdio.h>	// FILE, fopen()

char	*g_file_name = "./ole/only_skin";
FILE	*g_fp;

char	*get_next_line(int fd, int try);

int main()
{
	int i = -1;

	g_fp = fopen(g_file_name, "r");
	
	while(++i < 10)
	{
		printf("%i texto lido: >>> %s\n", i, get_next_line(g_fp->_fileno, i));
	}
	fclose(g_fp);
	return (0);
}