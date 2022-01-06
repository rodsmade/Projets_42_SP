/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:49:29 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/06 11:06:58 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	flush_all(t_pipe_cmds *pipe_cmds)
{
	ft_free_arr((void *)&pipe_cmds->cmd1_w_flags);
	ft_free_arr((void *)&pipe_cmds->cmd2_w_flags);
	ft_free_arr((void *)&pipe_cmds->all_paths);
	ft_free_ptr((void *)&pipe_cmds->cmd1_full_path);
	ft_free_ptr((void *)&pipe_cmds->cmd2_full_path);
	return ;
}

void	perror_exit(char *err_msg, int err_nbr, t_pipe_cmds *pipe_cmds)
{
	flush_all(pipe_cmds);
	perror(err_msg);
	exit(err_nbr);
}