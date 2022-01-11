#include "pipex.h"

// int main()
// {
// 	int	data[5];
// 	data[0] = 'd';
// 	data[1] = 'c';
// 	data[2] = 'b';
// 	data[3] = 'a';
// 	data[4] = '\0';

// 	printf("data:  %p\n", data);
// 	printf("&data: %p\n", &data);
// 	printf("\n");
	
// 	printf("data %%p: %p\n", data + 0);
// 	printf("data %%p: %p\n", &data[0]);
// 	printf("data %%c: %c\n", *(data + 0));
// 	printf("data %%p: %c\n", data[0]);
// 	printf("\n");

// 	printf("data %%p: %p\n", data + 1);
// 	printf("data %%p: %p\n", &data[1]);
// 	printf("data %%p: %c\n", *(data + 1));
// 	printf("data %%p: %c\n", data[1]);
// 	printf("\n");

// 	printf("data %%p: %p\n", data + 2);
// 	printf("data %%p: %p\n", &data[2]);
// 	printf("data %%c: %c\n", *(data + 2));
// 	printf("data %%c: %c\n", data[2]);
// 	printf("\n");

// 	printf("data %%p: %p\n", data + 3);
// 	printf("data %%p: %p\n", &data[3]);
// 	printf("data %%c: %c\n", *(data + 3));
// 	printf("data %%c: %c\n", data[3]);
// }

// int main()
// {
// 	char *ptr;
// 	char ptr2[] = "abcde";
// 	char *ptr3;

// 	ptr = ft_strdup("abcde");
// 	printf("1 %p\n", ptr);
// 	printf("1 %p\n", &ptr);
// 	printf("2 %p\n", ptr2);
// 	printf("2 %p\n", &ptr2);
// 	ptr3 = malloc(5);
// 	printf("3 %p\n", ptr3);
// 	printf("3 %p\n", &ptr3);

// 	// conclusão: quando NÃO DEU MALLOC: ptr e &ptr são o msm ponteiro
// 	//				quando DEU MALLOC: são diferentes
// 	return 0;
// }

// void	foo(char ***duplo)
// {
// 	printf("duplo: %p\n", *duplo);
// 	printf("duplo[0]: %s\n", (*duplo)[0]);
// 	printf("duplo[0]: %s\n", (*duplo)[1]);
// 	printf("duplo[0]: %s\n", (*duplo)[2]);
// 	printf("duplo[0]: %s\n", (*duplo)[3]);
// 	printf("duplo[0]: %s\n", (*duplo)[4]);
// 	return;
// }

// void	ft_free_arr(void ***arr)
// {
// 	int	i;

// 	i = -1;
// 	while ((*arr)[++i])
// 	{
// 		free((*arr)[i]);
// 		(*arr)[i] = NULL;
// 	}
// 	free(*arr);
// }

// int main()
// {
// 	char **duplo;
// 	char um[] = "um dois tres quatro";

// 	duplo = ft_split(um, ' ');

// 	foo(&duplo);

// 	ft_free_arr((void *)&duplo);
// 	return 0;
// }

int main(int argc, char *argv[], char *envp[])
{
	char *aloque;
	char	*cmd_ls[] = {"/usr/bin/ls", "ls", "-l", NULL};

	aloque = malloc(sizeof(aloque));
	printf("alocou\n");
	execve(cmd_ls[0], cmd_ls + 1, envp);
}