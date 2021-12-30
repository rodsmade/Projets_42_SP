#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// int main()
// {
// 	int pipe1[2];
// 	pipe(pipe1);
// 	printf("pipe1: [0]: %d, [1]: %d\n", pipe1[0], pipe1[1]);
// 	int pipe2[2];
// 	pipe(pipe2);
// 	printf("pipe1: [0]: %d, [1]: %d\n", pipe2[0], pipe2[1]);
// 	int pipe3[3];
// 	pipe(pipe3);
// 	printf("pipe1: [0]: %d, [1]: %d\n", pipe3[0], pipe3[1]);
// 	return (0);
// }

// entendendo como pipes são criados (mais de um no msm pgm)
// #define PROCESSES 5

// int main()
// {
// 	int i;
// 	int pipes[PROCESSES][2];

// 	i = -1;
// 	while (++i < PROCESSES)
// 	{
// 		pipe(pipes[i]);
// 		printf("pipe%d: [0]: %d, [1]: %d\n", i, pipes[i][0], pipes[i][1]);
// 	}
// }

/*
// entendendo como o access() funciona e se ele funciona pra identificar se um comando existe
// sei que /usr/local/bin/norminette existe. 
int main()
{
	printf("access return: %i\n", access("/sr/local/bin/norminette", F_OK));
	return 0;
}
*/

#include <string.h>
#include <stdlib.h>
#include "pipex.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	srclen;
// 	size_t	dstlen;
// 	size_t	i;

// 	srclen = ft_strlen(src);
// 	dstlen = 0;
// 	while (dst[dstlen] && dstlen < size)
// 		dstlen++;
// 	i = 0;
// 	if (dstlen < size)
// 	{
// 		while ((i + dstlen) < (size - 1) && src[i])
// 		{
// 			dst[i + dstlen] = src[i];
// 			i++;
// 		}
// 		dst[i + dstlen] = '\0';
// 	}
// 	return (dstlen + srclen);
// }

static char *find_path_variable(char **envp[])
{
	printf("DENTRO: envp: %p\n", envp);
	printf("DENTRO: *envp: %p\n", *envp);
	printf("DENTRO: **envp: %p\n", **envp);
	while(*envp)
	{
		if (ft_strncmp("PATH", **envp, 4) == 0)
			return (ft_strdup(**envp + 5));
		*envp = *envp + 1;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char *full_path_var;

	if (argc != 5)
	{
		printf("4 args parça\n");
		return (-1);
	}
	if (*argv == NULL)
	{
		printf("assim n da amig\n");
		return (-2);
	}
	printf("envp: %p\n", envp);
	printf("filho 1 de envp: %p -> %s\n", envp, *envp);
	printf("filho 2 de envp: %p -> %s\n", envp + 1, *(envp + 1));
	printf("endereço envp: %p\n", &envp);
	full_path_var = find_path_variable(&envp);
	if (full_path_var == NULL)
	{
		perror("PATH variable not found\n");
		return (-3);
	}
	char **path_split;
	int i;
	path_split = ft_split(full_path_var, ':');
	i = 0;
	while (path_split[i])
	{
		printf("env var: %s\n", path_split[i]);
		free(path_split[i]);
		i++;
	}
	free(full_path_var);
	free(path_split);
	return (0);
}