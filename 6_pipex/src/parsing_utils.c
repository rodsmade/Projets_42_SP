/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:17:25 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/13 19:54:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	mask_spaces(char **arg)
{
	int	i;

	i = -1;
	while ((*arg)[++i])
	{
		if ((*arg)[i] == '\"')
		{
			while ((*arg)[++i] != '"' && (*arg)[i] != '\0')
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = 1;
				i++;
			}
		}
		if ((*arg)[i] == '\'')
		{
			while ((*arg)[++i] != 39 && (*arg)[i] != '\0')
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = 1;
			}
		}
	}
}

static void	revert_spaces(char ***cmd_w_flags)
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

static void	remove_quotes(char ***cmd_w_flags)
{
	int	i;
	int	j;

	i = -1;
	while ((*cmd_w_flags)[++i] != NULL)
	{
		if ((*cmd_w_flags)[i][ft_strlen((*cmd_w_flags)[i]) - 1] == '\''
			|| (*cmd_w_flags)[i][ft_strlen((*cmd_w_flags)[i]) - 1] == '\"')
			(*cmd_w_flags)[i][ft_strlen((*cmd_w_flags)[i]) - 1] = '\0';
		if ((*cmd_w_flags)[i][0] == '\''
			|| (*cmd_w_flags)[i][0] == '\"')
		{
			j = 0;
			while ((*cmd_w_flags)[i][++j])
				(*cmd_w_flags)[i][j - 1] = (*cmd_w_flags)[i][j];
			(*cmd_w_flags)[i][j - 1] = '\0';
		}
	}
}

static char	**split_cmd(char *arg)
{
	char	**cmd_w_flags;

	mask_spaces(&arg);
	cmd_w_flags = ft_split(arg, ' ');
	revert_spaces(&cmd_w_flags);
	remove_quotes(&cmd_w_flags);
	return (cmd_w_flags);
}

void	retrieve_cmds_from_input(int argc, char *argv[], t_pipe_cmds *pipe_cmds)
{
	int	i;

	i = 1;
	while (++i < argc - 1)
	{
		argv[i] = ft_strtrim(argv[i], " ");
		pipe_cmds->cmds_w_flags[i - 2] = split_cmd(argv[i]);
	}
	return ;
}
