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

static char *find_path_variable(char **envp[])
{
	while(**envp)
	{
		// printf("entrou, envp[i]: %s\n", **envp);
		if (ft_strncmp("PATH", **envp, 4) == 0)
			return (ft_strdup(**envp + 5));
		*envp = *envp + 1;
	}
	return (NULL);
}

int	find_command(char *cmd, char **path_vars)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (path_vars[++i])
	{
		cmd_path = ft_slashcat(path_vars[i], cmd);
		// printf("cmd with path: %s\n", cmd_path);
		// printf("path: %s; access: %i\n", cmd_path, access(cmd_path, F_OK));
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free_ptr((void *)&cmd_path);
			return (1);
		}
		ft_free_ptr((void *)&cmd_path);
	}
	return (0);
}

void	basic_args_check(int argc, char *argv[])
{
	if (argc != 5)
	{
		perror("basic_args_check: 4 arguments needed \
					(e.g.: input_file \"cmd1\" \"cmd2\" output_file\n");
		exit(-1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		printf("basic_args_check: input file not found!\n");
		exit(-2);
	}
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*full_path_var;
	char	**path_vars;
	int		i;

	basic_args_check(argc, argv);
	full_path_var = find_path_variable(&envp);
	if (full_path_var == NULL)
	{
		// TODO: why the heck is this printing "success" on terminal
		perror("main: PATH variable not found\n");
		free(full_path_var);
		return (-1);
	}
	path_vars = ft_split(full_path_var, ':');
	if (!find_command(argv[1], path_vars))
	{
		printf("main: command %s not found\n", argv[1]);
		free(full_path_var);
		i = -1;
		while (path_vars[++i])
			free(path_vars[i]);
		free(path_vars);
		return (-1);
	}
	if (!find_command(argv[3], path_vars))
	{
		printf("main: command %s not found\n", argv[3]);
		free(full_path_var);
		i = -1;
		while (path_vars[++i])
			free(path_vars[i]);
		free(path_vars);
		return (-1);
	}
	// TODO: do_shit()
	printf("Found both commands %s and %s!!\n", argv[1], argv[3]);
	free(full_path_var);
	i = -1;
	while (path_vars[++i])
		free(path_vars[i]);
	free(path_vars);
	return (0);
}
