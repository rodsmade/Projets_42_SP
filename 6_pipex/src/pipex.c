/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:45:52 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 16:41:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mem_alloc(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->all_paths = NULL;
	pipe_cmds->pipes = NULL;
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

void	basic_args_check(int argc, char *argv[], t_pipe_cmds *pipe_cmds)
{
	if (argc < 5)
	{
		perror("basic_args_check: 4 arguments needed "
		"(e.g.: input_file \"cmd1\" \"cmd2\" output_file)");
		exit(2);
	}
	if (access(argv[1], F_OK) != 0)
	{
		perror("basic_args_check: input file not found!");
		exit(3);
	}
	pipe_cmds->cmd_count = argc - 3;
	pipe_cmds->pipe_count = pipe_cmds->cmd_count - 1;
	pipe_cmds->input_full_path = argv[1];
	pipe_cmds->output_full_path = argv[argc - 1];
	return ;
}

void	mask_spaces(char **arg)
{
	int	i;

	i = -1;
	while ((*arg)[++i])
	{
		if ((*arg)[i] == '\"')
		{
			while ((*arg)[++i] != '\"')
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = 1;
			}
		}
		if ((*arg)[i] == '\'')
		{
			while ((*arg)[++i] != '\'')
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = 1;
			}
		}
	}
}

void	revert_spaces(char ***cmd_w_flags)
{
	int	i;
	int	j;

	i = -1;
	while ((*cmd_w_flags)[++i] != NULL)
	{
		j = -1;
		while ((*cmd_w_flags)[i][++j])
		{
			if ((*cmd_w_flags)[i][j] == 1)
				(*cmd_w_flags)[i][j] = ' ';
		}
	}
}

char	**split_cmd(char *arg)
{
	char	**cmd_w_flags;

	mask_spaces(&arg);
	cmd_w_flags = ft_split(arg, ' ');
	revert_spaces(&cmd_w_flags);
	printf("DEBUG: fim split cmd\n");
	return (cmd_w_flags);
}

void	retrieve_cmds_from_input(int argc, char *argv[], t_pipe_cmds *pipe_cmds)
{
	int	i;

	i = 1;
	printf("argc - 1: %i\n", argc - 1);
	while (++i < argc - 1)
	{
		argv[i] = ft_strtrim(argv[i], " ");
		pipe_cmds->cmds_w_flags[i - 2] = split_cmd(argv[i]);
		printf("pipe_cmds->cmds_w_flags[i - 2]: %s\n", pipe_cmds->cmds_w_flags[i - 2][0]);
		printf("pipe_cmds->cmds_w_flags[i - 2]: %s\n", pipe_cmds->cmds_w_flags[i - 2][1]);
		printf("pipe_cmds->cmds_w_flags[i - 2]: %s\n", pipe_cmds->cmds_w_flags[i - 2][2]);
		printf("DEBUG: ué\n");
	}
	return ;
}

static void	find_path_variable(char *envp[], t_pipe_cmds *pipe_cmds)
{
	char	*full_path_var;

	full_path_var = NULL;
	while(*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			full_path_var = ft_strdup(*envp + 5);
		envp = envp + 1;
	}
	if (full_path_var == NULL)
		perror_exit("main: PATH variable not found", 4, pipe_cmds);
	pipe_cmds->all_paths = ft_split(full_path_var, ':');
	ft_free_ptr((void *)&full_path_var);
	return ;
}

int	find_command(char *cmd, char **all_paths)
{
	int		i;
	int		access_ok;
	char	*cmd_fullpath;

	access_ok = 0;
	i = -1;
	while (all_paths[++i])
	{
		cmd_fullpath = ft_slashcat(all_paths[i], cmd);
		if (access(cmd_fullpath, F_OK) == 0)
			access_ok = 1;
		ft_free_ptr((void *)&cmd_fullpath);
	}
	return (access_ok);
}

void	search_cmds_in_paths(t_pipe_cmds *pipe_cmds)
{
	int	i;

	i = -1;
	while (pipe_cmds->cmds_w_flags[++i])
	{
		if (!find_command((pipe_cmds->cmds_w_flags[i])[0],
			pipe_cmds->all_paths))
			perror_exit("main: command not found", 5, pipe_cmds);
	}
	return ;
}

/*
$> ./pipex infile "ls -l" "wc -l" outfile
devrait être le même que "< infile ls -l | wc -l > outfile"
*/
int	main(int argc, char *argv[], char *envp[])
{
	t_pipe_cmds	pipe_cmds;

	basic_args_check(argc, argv, &pipe_cmds);
	printf("DEBUG: passou 0\n");
	mem_alloc(&pipe_cmds);
	printf("DEBUG: passou 1\n");
	retrieve_cmds_from_input(argc, argv, &pipe_cmds);
	printf("DEBUG: passou 2\n");
	find_path_variable(envp, &pipe_cmds);
	printf("DEBUG: passou 3\n");
	search_cmds_in_paths(&pipe_cmds);
	printf("DEBUG: passou 4\n");
	printf("Found both commands %s and %s!!\n", argv[2], argv[3]);
	exec_chained_pipe(&pipe_cmds, envp);
	printf("DEBUG: passou 5\n");
	flush_all(&pipe_cmds);
	printf("DEBUG: passou 6\n");
	return (0);
}
