/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:45:52 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 21:18:19 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_path_variable(char *envp[], t_pipe_cmds *pipe_cmds)
{
	char	*full_path_var;

	full_path_var = NULL;
	while (*envp)
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

int	find_command(t_pipe_cmds *pipe_cmds, int j)
{
	int		i;
	char	*cmd_fullpath;

	i = -1;
	while (pipe_cmds->all_paths[++i])
	{
		cmd_fullpath = ft_slashcat(pipe_cmds->all_paths[i],
				pipe_cmds->cmds_w_flags[j][0]);
		if (access(cmd_fullpath, F_OK) == 0)
		{
			pipe_cmds->cmds_full_path[j] = cmd_fullpath;
			return (1);
		}
		ft_free_ptr((void *)&cmd_fullpath);
	}
	return (0);
}

void	search_cmds_in_paths(t_pipe_cmds *pipe_cmds)
{
	int	i;

	i = -1;
	while (pipe_cmds->cmds_w_flags[++i])
	{
		if (!find_command(pipe_cmds, i))
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
	mem_alloc(&pipe_cmds);
	retrieve_cmds_from_input(argc, argv, &pipe_cmds);
	find_path_variable(envp, &pipe_cmds);
	search_cmds_in_paths(&pipe_cmds);
	exec_chained_pipe(&pipe_cmds, envp);
	return (0);
}
