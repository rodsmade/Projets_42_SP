/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:45:13 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/13 18:03:25 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// -- INCLUDE -----------------------------------------------------------------|
// perror()
# include <stdio.h>
# include <errno.h>
// strerror()
# include <string.h>
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
	char	*errmsg;
}	t_pipe_cmds;

// -- PROTOTYPES --------------------------------------------------------------|
// exec_pipe_utils.c
int		exec_chained_pipe(t_pipe_cmds *pipe_cmds, char *envp[]);

// exit_utils.c
void	flush_all(t_pipe_cmds *pipe_cmds);
void	perror_exit(char *err_msg, int err_nbr, t_pipe_cmds *pipe_cmds);

// init_utils.c
void	basic_args_check(int argc, char *argv[], t_pipe_cmds *pipe_cmds);
void	make_pipes(t_pipe_cmds *pipe_cmds);
void	mem_alloc(t_pipe_cmds *pipe_cmds);
void	open_files(t_pipe_cmds *pipe_cmds);

// libft_utils_1.c
void	ft_bzero(void *s, size_t n);
void	ft_free_arr(void ***arr);
void	ft_free_ptr(void **ptr);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// libft_utils_2.c
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_slashcat(const char *str1, const char *str2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

// libft_utils_3.c
char	*ft_strtrim(char *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// libft_utils_ftsplit.c
char	**ft_split(char const *s, char delimiter);

// parsing_utils.c
void	retrieve_cmds_from_input(int argc, char *argv[],
			t_pipe_cmds *pipe_cmds);

// pipex.c
void	find_path_variable(char *envp[], t_pipe_cmds *pipe_cmds);
void	search_cmds_in_paths(t_pipe_cmds *pipe_cmds);
int		find_command(t_pipe_cmds *pipe_cmds, int j);

#endif