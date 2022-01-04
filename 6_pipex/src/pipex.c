/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:45:52 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/04 20:01:49 by roaraujo         ###   ########.fr       */
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

static char **find_path_variable(char **envp[])
{
	char	*full_path_var;
	char	**paths_arr;

	full_path_var = NULL;
	while(**envp)
	{
		if (ft_strncmp("PATH", **envp, 4) == 0)
			full_path_var = ft_strdup(**envp + 5);
		*envp = *envp + 1;
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

int	find_command(char *cmd, char **path_vars)
{
	int		i;
	char	**cmd_path;

	printf("cmd: %s\n", cmd);
	i = -1;
	while (path_vars[++i])
	{
		cmd_path = ft_split(cmd, ' ');
		cmd_path[0] = ft_slashcat(path_vars[i], cmd_path[0]);
		if (access(cmd_path[0], F_OK) == 0)
		{
			ft_free_ptr((void *)&cmd_path[0]);
			return (1);
		}
		ft_free_ptr((void *)&cmd_path[0]);
	}
	return (0);
}

/*
$> ./pipex infile "ls -l" "wc -l" outfile
devrait être le même que "< infile ls -l | wc -l > outfile"
*/
int	main(int argc, char *argv[], char *envp[])
{
	char	**path_vars;
	int		i;

	basic_args_check(argc, argv);
	path_vars = find_path_variable(&envp);
	i = 1;
	while (++i < argc)
	{
		ft_strtrim(argv[i], " ");
	}
	if (!find_command(argv[2], path_vars))
	{
		printf("main: command %s not found\n", argv[2]);
		i = -1;
		while (path_vars[++i])
			free(path_vars[i]);
		free(path_vars);
		return (-1);
	}
	if (!find_command(argv[3], path_vars))
	{
		printf("main: command %s not found\n", argv[3]);
		i = -1;
		while (path_vars[++i])
			free(path_vars[i]);
		free(path_vars);
		return (-1);
	}
	// TODO: do_shit()
	printf("Found both commands %s and %s!!\n", argv[2], argv[3]);
	i = -1;
	while (path_vars[++i])
		free(path_vars[i]);
	free(path_vars);
	return (0);
}
