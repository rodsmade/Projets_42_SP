#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

// int	BUFFER_SIZE; // escolhi passar o buffer_size como argv por praticidade

int main(void)
{
	char	*file_path = "./testin";
	char	**line;
	int		gnl_return;
	FILE	*fptr;

	// if (argc != 2)
	// {
	// 	printf("ERRRRROUU!!\n");
	// 	return (-1);
	// }

	// // buffer_size vem do argv e não da compilação
	// BUFFER_SIZE = atoi(argv[1]);
	
	// abre o arquivo que eu quero
	fptr = fopen(file_path, "r");
	printf("File descriptor is: %i\n\n\n\n", fptr->_fileno);

	// eu já sei de antemão quantas linhas existem no arquivo então
	line = malloc((211 + 1) * sizeof(*line));
	if (line == NULL)
		return (-1);
	line[211] = NULL;

	// chama gnl em loop, até dar ruim ou até chegar ao fim do arquivo
	int i = 0;
	while((gnl_return = get_next_line(fptr->_fileno, line)) > 0)
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