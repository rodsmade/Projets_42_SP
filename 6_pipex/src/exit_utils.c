/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:49:29 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 21:05:02 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	flush_all(t_pipe_cmds *pipe_cmds)
{
	int	i;

	i = -1;
	while (pipe_cmds->cmds_w_flags[++i])
		ft_free_arr((void *)&(pipe_cmds->cmds_w_flags[i]));
	ft_free_ptr((void *)&pipe_cmds->cmds_w_flags);
	ft_free_arr((void *)&pipe_cmds->cmds_full_path);
	ft_free_arr((void *)&pipe_cmds->all_paths);
	if (pipe_cmds->pipes)
		ft_free_arr((void *)&pipe_cmds->pipes);
	return ;
}

void	perror_exit(char *err_msg, int err_nbr, t_pipe_cmds *pipe_cmds)
{
	flush_all(pipe_cmds);
	perror(err_msg);
	exit(err_nbr);
}
