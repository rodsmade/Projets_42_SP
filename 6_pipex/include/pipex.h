/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:45:13 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 20:51:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// -- INCLUDE -----------------------------------------------------------------|
// perror()
# include <stdio.h>
// exit()
# include <stdlib.h>
// access()
# include <unistd.h>
// open()
# include <fcntl.h>
// wait()
# include <sys/types.h>
# include <sys/wait.h>

// -- TYPEDEFS (structs) ------------------------------------------------------|
typedef struct s_pipe_cmds
{
	int		cmd_count;
	int		pipe_count;
	char	*input_full_path;
	int		input_fd;
	char	*output_full_path;
	int		output_fd;
	char	**all_paths;	
	char	**cmds_full_path;
	char	***cmds_w_flags;
	int		**pipes;
	int		is_here_doc;
}	t_pipe_cmds;

// -- PROTOTYPES --------------------------------------------------------------|
// libft_utils_ftsplit.c
char	**ft_split(char const *s, char delimiter);

// libft_utils.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_slashcat(const char *str1, const char *str2);
void	ft_free_arr(void ***arr);
void	ft_free_ptr(void **ptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char *s1, char const *set);

// exit_utils.c
void	flush_all(t_pipe_cmds *pipe_cmds);
void	perror_exit(char *err_msg, int err_nbr, t_pipe_cmds *pipe_cmds);

// exec_pipe_utils.c
int		exec_chained_pipe(t_pipe_cmds *pipe_cmds, char *envp[]);

#endif