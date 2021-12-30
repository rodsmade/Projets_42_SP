/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:15:18 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/29 15:07:51 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	command_exists(char *cmd, char **envp[])
{

	ft_strlcat()
	return ();
}

static void	check_args(char **argv[], char **envp[])
{
	int		i;
	char	**cmd;

	i = 0;
	while (++i < 3)
	{
		cmd = ft_split(argv[i]);
		if (!command_exists(cmd[0], envp) || !command_exists(cmd[2], envp))
		{
			perror("Command not found");
			exit(-2);
		}
		while(*cmd)
			ft_free_ptr(*cmd);
		ft_free_ptr(cmd);
	}
	return ;
}

/**
 * ./pipex file1 cmd1 cmd2 file2
 * MUST CORRESPOND TO
 * < file1 cmd1 | cmd2 > file2
 * */
int	main(int argc, char *argv[], char *envp[])
{
	// diacho como entender essa entrada a a a :'(
	// quantos args de entrada tem q ter no minimo? no máximo?
	if (argc != 5)
	{
		perror("wrong number arguments (4 allowed)");
		exit(-1);
	}
	check_args(&argv, &envp);
	return (0);
}
