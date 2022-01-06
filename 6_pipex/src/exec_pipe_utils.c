/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/05 16:41:03 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define PROCESS_NO 2

void	run_cmd(int *pipefd)
{
	int my_value;

	my_value = getpid() % PROCESS_NO;
	printf("I'm a child, pid: %d, ppid: %d\n  my_value: %d\n  pipefd[0]: %d pipefd[1]: %d\n", getpid(), getppid(), my_value, pipefd[0], pipefd[1]);
	close(pipefd[0]);
	write(pipefd[1], &my_value, sizeof(int));
	close(pipefd[1]);
	return ;
}

int exec_chained_pipe(char ***cmd1, char ***cmd2, char ***all_paths)
{
	int i;
	int pid;
	int	pipefd[PROCESS_NO][2];

	i = -1;
	while (++i < PROCESS_NO)
	{
		if (pipe(pipefd[i]) == -1)
			return (-1);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			run_cmd(pipefd[i]);
			return (0) ;
		}
	}
	i = -1;
	while (++i < PROCESS_NO)
		wait(NULL);
	return (0);
}