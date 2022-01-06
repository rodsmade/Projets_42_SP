/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:45:52 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/06 11:28:46 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char **find_path_variable(char *envp[])
{
	char	*full_path_var;
	char	**paths_arr;

	full_path_var = NULL;
	while(*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			full_path_var = ft_strdup(*envp + 5);
		envp = envp + 1;
	}
	if (full_path_var == NULL)
	{
		// TODO: why the heck is this printing "success" on terminal
		perror("main: PATH variable not found\n");
		exit(3);
	}
	paths_arr = ft_split(full_path_var, ':');
	ft_free_ptr((void *)&full_path_var);
	return (paths_arr);
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

void	free_all(char ***all_paths, char ***cmd1, char ***cmd2)
{
	ft_free_arr((void *)cmd1);
	ft_free_arr((void *)cmd2);
	ft_free_arr((void *)all_paths);
	return ;
}

void	search_commands(char ***cmd1, char ***cmd2, char ***all_paths)
{
	if (!find_command((*cmd1)[0], *all_paths))
	{
		perror("main: command 1 not found");
		free_all(cmd1, cmd2, all_paths);
		exit(3);
	}
	if (!find_command((*cmd2)[0], *all_paths))
	{
		perror("main: command 2 not found");
		free_all(cmd1, cmd2, all_paths);
		exit(4);
	}
	return ;
}

void	mem_alloc(t_pipe_cmds *pipe_cmds)
{
	pipe_cmds->all_paths = NULL;
	pipe_cmds->cmd1_w_flags = NULL;
	pipe_cmds->cmd2_w_flags = NULL;
	pipe_cmds->cmd1_full_path = NULL;
	pipe_cmds->cmd2_full_path = NULL;
	pipe_cmds->all_paths = ft_calloc(1, sizeof(pipe_cmds->all_paths));
	pipe_cmds->cmd1_w_flags = ft_calloc(1, sizeof(pipe_cmds->cmd1_w_flags));
	pipe_cmds->cmd2_w_flags = ft_calloc(1, sizeof(pipe_cmds->cmd2_w_flags));
	pipe_cmds->cmd1_full_path = ft_calloc(1, sizeof(pipe_cmds->cmd1_full_path));
	pipe_cmds->cmd2_full_path = ft_calloc(1, sizeof(pipe_cmds->cmd2_full_path));
	if (!pipe_cmds->all_paths || !pipe_cmds->cmd1_w_flags
		|| !pipe_cmds->cmd2_w_flags || !pipe_cmds->cmd1_full_path
		|| !pipe_cmds->cmd2_full_path)
		perror_exit("mem_alloc: error allocating memory", 3, pipe_cmds);
	return ;
}

/*
$> ./pipex infile "ls -l" "wc -l" outfile
devrait être le même que "< infile ls -l | wc -l > outfile"
*/
int	main(int argc, char *argv[], char *envp[])
{
	int			i;
	char		**cmd1;
	char		**cmd2;
	char		**all_paths;
	t_pipe_cmds	pipe_cmds;

	printf("DEBUG: passou 0\n");
	mem_alloc(&pipe_cmds);
	basic_args_check(argc, argv);
	// mudar ao invés de find_path devolver, deixar montado no structzão
	all_paths = find_path_variable(envp);
	// retrieve_cmds_from_input(argc, argv, structzão);
	i = 1;
	while (++i < argc)
		argv[i] = ft_strtrim(argv[i], " ");
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	search_commands(&cmd1, &cmd2, &all_paths);
	printf("Found both commands %s and %s!!\n", argv[2], argv[3]);
	// exec_chained_pipe(&cmd1, &cmd2, &all_paths);
	free_all(&cmd1, &cmd2, &all_paths);
	return (0);
}
