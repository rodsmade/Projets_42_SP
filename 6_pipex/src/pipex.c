/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:45:52 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/09 10:46:49 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mem_alloc(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->all_paths = NULL;
	pipe_cmds->cmd1_w_flags = NULL;
	pipe_cmds->cmd2_w_flags = NULL;
	pipe_cmds->cmd1_full_path = NULL;
	pipe_cmds->cmd2_full_path = NULL;
	pipe_cmds->cmd1_full_path = ft_calloc(1, sizeof(pipe_cmds->cmd1_full_path));
	pipe_cmds->cmd2_full_path = ft_calloc(1, sizeof(pipe_cmds->cmd2_full_path));
	if (!pipe_cmds->cmd1_full_path || !pipe_cmds->cmd2_full_path)
		perror_exit("mem_alloc: error allocating memory", 3, pipe_cmds);
	return ;
}

void	basic_args_check(int argc, char *argv[])
{
	if (argc < 5)
	{
		perror("basic_args_check: 4 arguments needed "
		"(e.g.: input_file \"cmd1\" \"cmd2\" output_file)");
		exit(1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		perror("basic_args_check: input file not found!");
		exit(2);
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

void	search_commands(t_pipe_cmds *pipe_cmds)
{
	if (!find_command((pipe_cmds->cmd1_w_flags)[0], pipe_cmds->all_paths))
		perror_exit("main: command 1 not found", 5, pipe_cmds);
	if (!find_command((pipe_cmds->cmd2_w_flags)[0], pipe_cmds->all_paths))
		perror_exit("main: command 2 not found", 6, pipe_cmds);
	return ;
}

void	retrieve_cmds_from_input(int argc, char *argv[], t_pipe_cmds *pipe_cmds)
{
	int	i;

	basic_args_check(argc, argv);
	pipe_cmds->cmd_count = argc - 3;
	pipe_cmds->input_full_path = argv[1];
	pipe_cmds->output_full_path = argv[argc];
	i = 1;
	while (++i < argc)
		argv[i] = ft_strtrim(argv[i], " ");
	pipe_cmds->cmd1_w_flags = ft_split(argv[2], ' ');
	pipe_cmds->cmd2_w_flags = ft_split(argv[3], ' ');
}

/*
$> ./pipex infile "ls -l" "wc -l" outfile
devrait être le même que "< infile ls -l | wc -l > outfile"
*/
int	main(int argc, char *argv[], char *envp[])
{
	t_pipe_cmds	pipe_cmds;

	// printf("DEBUG: passou 0\n");
	mem_alloc(&pipe_cmds);
	// printf("DEBUG: passou 1\n");
	retrieve_cmds_from_input(argc, argv, &pipe_cmds);
	// printf("DEBUG: passou 2\n");
	find_path_variable(envp, &pipe_cmds);
	// printf("DEBUG: passou 3\n");
	search_commands(&pipe_cmds);
	// printf("DEBUG: passou 4\n");
	printf("Found both commands %s and %s!!\n", argv[2], argv[3]);
	exec_chained_pipe(&pipe_cmds, envp);
	// printf("DEBUG: passou 5\n");
	flush_all(&pipe_cmds);
	// printf("DEBUG: passou 6\n");
	return (0);
}
