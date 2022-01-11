/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 10:47:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	make_pipes(t_pipe_cmds *pipe_cmds)
{
	int	i;

	pipe_cmds->pipes = ft_calloc(pipe_cmds->cmd_count + 1, 2 * sizeof(int));
	if (pipe_cmds->pipes == NULL)
		perror_exit("make_pipes: error allocating memory for pipes pointer",
			7, pipe_cmds);
	pipe_cmds->pipes[pipe_cmds->cmd_count] = NULL;
	i = -1;
	// printf("cmd count: %i\n", pipe_cmds->cmd_count);
	while (++i < pipe_cmds->cmd_count)
	{
		pipe_cmds->pipes[i] = ft_calloc(2, sizeof(int));
		if (pipe_cmds->pipes[i] == NULL)
			perror_exit("make_pipes: error allocating memory for pipe pointer",
				8, pipe_cmds);
		if (pipe(pipe_cmds->pipes[i]) == -1)
			perror_exit("make_pipes: error creating pipes", 9, pipe_cmds);
		// printf("pipe criado: [%i, %i]\n", pipe_cmds->pipes[i][0], pipe_cmds->pipes[i][1]);
	}
	printf("chegou aqui\n");
	return ;
}

static void	open_files(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->input_fd = open(pipe_cmds->input_full_path, O_RDONLY);
	if (pipe_cmds->input_fd == -1)
		perror_exit("open_files: error opening input file", 10, pipe_cmds);
	if (pipe_cmds->is_here_doc)
	{
		pipe_cmds->output_fd = open(pipe_cmds->input_full_path,
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (pipe_cmds->output_fd == -1)
			perror_exit("open_files: error opening output file", 11, pipe_cmds);
	}
	else
	{
		pipe_cmds->output_fd = open(pipe_cmds->input_full_path,
			O_CREAT | O_WRONLY, 0777);
		if (pipe_cmds->output_fd == -1)
			perror_exit("open_files: error opening output file", 12, pipe_cmds);
	}
	return ;
}

static void	run_first_cmd(t_pipe_cmds *pipe_cmds, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("run_first_cmd: error while fork", 13, pipe_cmds);
	if (pid == 0)
	{
		if (dup2(pipe_cmds->input_fd, STDIN_FILENO) == -1)
			perror_exit("run_first_cmd: error duplicating file descriptor",
				14, pipe_cmds);
		if (dup2(pipe_cmds->pipes[0][1], STDOUT_FILENO) == -1)
			perror_exit("run_first_cmd: error duplicating file descriptor",
				15, pipe_cmds);
		if (execve(pipe_cmds->cmds_full_path[0], pipe_cmds->cmds_w_flags[0],
			envp) == -1)
			perror_exit("run_first_cmd: error in exec function", 16, pipe_cmds);
	}
	else
		wait(NULL);
}

static void	run_nth_cmd(t_pipe_cmds *pipe_cmds, char *envp[], int i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("run_nth_cmd: error while forking", 17, pipe_cmds);
	if (pid == 0)
	{
		if (dup2(pipe_cmds->pipes[i - 1][0], STDIN_FILENO) == -1)
			perror_exit("run_nth_cmd: error duplicating file descriptor",
				18, pipe_cmds);
		if (dup2(pipe_cmds->pipes[i][1], STDOUT_FILENO) == -1)
			perror_exit("run_nth_cmd: error duplicating file descriptor",
				19, pipe_cmds);
		if (execve(pipe_cmds->cmds_full_path[i], pipe_cmds->cmds_w_flags[i],
			envp) == -1)
			perror_exit("run_nth_cmd: error in exec function", 20, pipe_cmds);
	}
	else
		wait(NULL);
}

static void	run_last_cmd(t_pipe_cmds *pipe_cmds, char *envp[])
{
	if (dup2(pipe_cmds->pipes[pipe_cmds->process_count - 1][0],
		STDIN_FILENO) == -1)
		perror_exit("run_last_cmd: error duplicating file descriptor",
			22, pipe_cmds);
	if (dup2(pipe_cmds->output_fd, STDOUT_FILENO) == -1)
		perror_exit("run_last_cmd: error duplicating file descriptor",
			23, pipe_cmds);
	if (execve(pipe_cmds->cmds_full_path[pipe_cmds->cmd_count - 1],
		pipe_cmds->cmds_w_flags[pipe_cmds->cmd_count - 1], envp) == -1)
		perror_exit("run_last_child: error in exec function",
			24, pipe_cmds);
}

int exec_chained_pipe(t_pipe_cmds *pipe_cmds, char *envp[])
{
	int	i;
	make_pipes(pipe_cmds);
	open_files(pipe_cmds);
	//TODO:  na real acho que dá pra fazer 1 função só e não 3 pq não eh mta linha
	run_first_cmd(pipe_cmds, envp);
	i = 1;
	while (i < pipe_cmds->cmd_count - 1)
	{
		run_nth_cmd(pipe_cmds, envp, i);
		i++;
	}
	run_last_cmd(pipe_cmds, envp);
	printf("chegou aqui2\n");
	return (0);
}
