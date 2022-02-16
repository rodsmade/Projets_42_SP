/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/02/16 17:07:50 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	flush_cmd(t_pipe_cmds *pipe_cmds, int i)
{
	int	len;

	pipe_cmds->errmsg = ft_strjoin(pipe_cmds->cmds_w_flags[i][0],
			": command not found\n");
	len = ft_strlen(pipe_cmds->errmsg);
	i = write(2, pipe_cmds->errmsg, len);
	flush_all(pipe_cmds);
	exit(127);
	return ;
}

static void	run_first_cmd(t_pipe_cmds *pipe_cmds, char *envp[])
{
	int	pid;
	int	exit_code;

	pid = fork();
	if (pid == -1)
		perror_exit("run_first_cmd: error while forking", 13, pipe_cmds);
	if (pid == 0)
	{
		close(pipe_cmds->pipes[0][0]);
		if (!find_command(pipe_cmds, 0))
			flush_cmd(pipe_cmds, 0);
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
	{
		waitpid(pid, &exit_code, WNOHANG);
		close(pipe_cmds->pipes[0][1]);
	}
}

static void	run_nth_cmd(t_pipe_cmds *pipe_cmds, char *envp[], int i)
{
	int	pid;
	int	exit_code;

	pid = fork();
	if (pid == -1)
		perror_exit("run_nth_cmd: error while forking", 17, pipe_cmds);
	if (pid == 0)
	{
		close(pipe_cmds->pipes[i - 1][1]);
		close(pipe_cmds->pipes[i][0]);
		if (!find_command(pipe_cmds, i))
			flush_cmd(pipe_cmds, i);
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
		waitpid(pid, &exit_code, WNOHANG);
}

static void	run_last_cmd(t_pipe_cmds *pipe_cmds, char *envp[])
{
	close(pipe_cmds->pipes[pipe_cmds->pipe_count - 1][1]);
	if (!find_command(pipe_cmds, pipe_cmds->cmd_count - 1))
		flush_cmd(pipe_cmds, pipe_cmds->cmd_count - 1);
	if (dup2(pipe_cmds->pipes[pipe_cmds->pipe_count - 1][0],
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

int	exec_chained_pipe(t_pipe_cmds *pipe_cmds, char *envp[])
{
	int	i;

	make_pipes(pipe_cmds);
	open_files(pipe_cmds);
	run_first_cmd(pipe_cmds, envp);
	i = 1;
	while (i < pipe_cmds->cmd_count - 1)
	{
		run_nth_cmd(pipe_cmds, envp, i);
		i++;
	}
	run_last_cmd(pipe_cmds, envp);
	return (0);
}
