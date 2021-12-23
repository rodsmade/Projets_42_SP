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

// entendendo como o access() funciona e se ele funciona pra identificar se um comando existe
// sei que /usr/local/bin/norminette existe. 
int main()
{
	printf("access return: %i\n", access("/sr/local/bin/norminette", F_OK));
	return 0;
}