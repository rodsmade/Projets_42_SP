/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/07 14:10:32 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define PROCESS_NO 2

void	run_cmd(void)
{
	// int my_value;

	// my_value = getpid() % PROCESS_NO;
	// printf("I'm a child, pid: %d, ppid: %d\n  my_value: %d\n  pipefd[0]: %d pipefd[1]: %d\n", getpid(), getppid(), my_value, pipefd[0], pipefd[1]);
	// close(pipefd[0]);
	// write(pipefd[1], &my_value, sizeof(int));
	// close(pipefd[1]);
	return ;
}

void	make_pipes(t_pipe_cmds *pipe_cmds)
{
	int	i;

	pipe_cmds->pipes = ft_calloc(pipe_cmds->cmd_count + 1, 2 * sizeof(int));
	if (pipe_cmds->pipes == NULL)
		perror_exit("make_pipes: error allocating memory for pipes",
			10, pipe_cmds);
	pipe_cmds->pipes[pipe_cmds->cmd_count] = NULL;
	i = -1;
	// printf("cmd count: %i\n", pipe_cmds->cmd_count);
	while (++i < pipe_cmds->cmd_count)
	{
		pipe_cmds->pipes[i] = ft_calloc(2, sizeof(int));
		if (pipe_cmds->pipes[i] == NULL)
			perror_exit("make_pipes: error allocating memory for pipes",
				11, pipe_cmds);
		if (pipe(pipe_cmds->pipes[i]) == -1)
			perror_exit("make_pipes: error creating pipes", 12, pipe_cmds);
		// printf("pipe criado: [%i, %i]\n", pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
	}
	return ;
}

int exec_chained_pipe(t_pipe_cmds *pipe_cmds, char *envp[])
{
	int i;
	// int pid;

	make_pipes(pipe_cmds);
	pipe_cmds->input_fd = open(pipe_cmds->input_full_path, O_RDONLY);
	pipe_cmds->output_fd = open(pipe_cmds->input_full_path,
		O_CREAT | O_WRONLY | O_TRUNC, 0777);
	// printf("input fd: %i\n", pipe_cmds->input_fd);
	// printf("output fd: %i\n", pipe_cmds->output_fd);
	// printf("pipe_cmds->pipes[0] era: [%i, %i]\n", pipe_cmds->pipes[0][0], pipe_cmds->pipes[0][1]);
	pipe_cmds->pipes[0][0] = pipe_cmds->input_fd;
	// printf("pipe_cmds->pipes[0] é:   [%i, %i]\n", pipe_cmds->pipes[0][0], pipe_cmds->pipes[0][1]);
	i = -1;
	while (++i < pipe_cmds->cmd_count - 1)
	{
		// printf("pipe_cmds->pipes[%i] era: [%i, %i]\n", i, pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
		pipe_cmds->pipes[i][1] = pipe_cmds->pipes[i + 1][1];
		// printf("pipe_cmds->pipes[%i] é:   [%i, %i]\n", i, pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
	}
	// printf("pipe_cmds->pipes[%i] era: [%i, %i]\n", i, pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
	pipe_cmds->pipes[pipe_cmds->cmd_count - 1][1] = pipe_cmds->output_fd;
	// printf("pipe_cmds->pipes[%i] é:   [%i, %i]\n", i, pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
	
	// i = -1;
	// while (++i < PROCESS_NO)
	// {
	// 	pid = fork();
	// 	if (pid == -1)
	// 		return (-1);
	// 	if (pid == 0)
	// 	{
	// 		run_cmd();
	// 		return (0) ;
	// 	}
	// }
	// // NO PROCESSO PAI TEM QUE FECHAR OS FDS PQ OS PROCESSOS FILHOS O EXEC NAO RETORNA (SE DER BOM)
	// i = -1;
	// while (++i < PROCESS_NO)
	// 	wait(NULL);
	return (0);
}