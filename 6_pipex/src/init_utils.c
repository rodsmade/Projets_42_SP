/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:13:59 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:44 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	basic_args_check(int argc, char *argv[], t_pipe_cmds *pipe_cmds)
{
	char	*errmsg;

	if (argc != 5)
	{
		perror("basic_args_check: invalid number of arguments "
			"(use: input_file \"cmd1\" \"cmd2\" output_file)");
		exit(2);
	}
	if (access(argv[1], F_OK) != 0)
	{
		errmsg = ft_strjoin("bash: ", argv[1]);
		perror(errmsg);
		free(errmsg);
		exit(1);
	}
	pipe_cmds->cmd_count = argc - 3;
	pipe_cmds->pipe_count = pipe_cmds->cmd_count - 1;
	pipe_cmds->input_full_path = argv[1];
	pipe_cmds->output_full_path = argv[argc - 1];
	return ;
}

void	make_pipes(t_pipe_cmds *pipe_cmds)
{
	int	i;

	pipe_cmds->pipes = ft_calloc(pipe_cmds->pipe_count + 1,
			sizeof(pipe_cmds->pipes));
	if (pipe_cmds->pipes == NULL)
		perror_exit("make_pipes: error allocating memory for pipes pointer",
			7, pipe_cmds);
	pipe_cmds->pipes[pipe_cmds->pipe_count] = NULL;
	i = -1;
	while (++i < pipe_cmds->pipe_count)
	{
		pipe_cmds->pipes[i] = ft_calloc(2, sizeof(int));
		if (pipe_cmds->pipes[i] == NULL)
			perror_exit("make_pipes: error allocating memory for pipe pointer",
				8, pipe_cmds);
		if (pipe(pipe_cmds->pipes[i]) == -1)
			perror_exit("make_pipes: error creating pipes", 9, pipe_cmds);
	}
	return ;
}

void	mem_alloc(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->is_here_doc = 0;
	pipe_cmds->all_paths = NULL;
	pipe_cmds->pipes = NULL;
	pipe_cmds->errmsg = NULL;
	pipe_cmds->cmds_full_path = ft_calloc(pipe_cmds->cmd_count + 1,
			sizeof(pipe_cmds->cmds_full_path));
	pipe_cmds->cmds_w_flags = ft_calloc(pipe_cmds->cmd_count + 1,
			sizeof(pipe_cmds->cmds_w_flags));
	if (!pipe_cmds->cmds_full_path
		|| !pipe_cmds->cmds_w_flags)
		perror_exit("mem_alloc: error allocating memory", 1, pipe_cmds);
	pipe_cmds->cmds_full_path[pipe_cmds->cmd_count] = NULL;
	pipe_cmds->cmds_w_flags[pipe_cmds->cmd_count] = NULL;
	return ;
}

void	open_files(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->input_fd = open(pipe_cmds->input_full_path, O_RDONLY);
	if (pipe_cmds->input_fd == -1)
	{
		pipe_cmds->errmsg = ft_strjoin("bash: ", pipe_cmds->input_full_path);
		printf("err msg: %s\n", pipe_cmds->errmsg);
		perror_exit(pipe_cmds->errmsg, 0, pipe_cmds);
	}
	pipe_cmds->output_fd = open(pipe_cmds->output_full_path,
			O_CREAT | O_WRONLY, 0777);
	if (pipe_cmds->output_fd == -1)
	{
		pipe_cmds->errmsg = ft_strjoin("bash: ", pipe_cmds->output_full_path);
		perror_exit(pipe_cmds->errmsg, 1, pipe_cmds);
	}
	return ;
}
