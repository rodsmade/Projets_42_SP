/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:45:13 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/06 11:08:03 by roaraujo         ###   ########.fr       */
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

// -- TYPEDEFS (structs) ------------------------------------------------------|
typedef struct s_pipe_cmds
{
	char	**all_paths;
	char	**cmd1_w_flags;
	char	**cmd2_w_flags;
	char	*cmd1_full_path;
	char	*cmd2_full_path;
}	t_pipe_cmds;

// -- PROTOTYPES --------------------------------------------------------------|
// libft_utils_ftsplit.c
char	**ft_split(char const *s, char delimiter);

// libft_utils.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_slashcat(const char* str1, const char *str2);
void	ft_free_arr(void ***arr);
void	ft_free_ptr(void **ptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char *s1, char const *set);

// other_utils.c
void	flush_all(t_pipe_cmds *pipe_cmds);
void	perror_exit(char *err_msg, int err_nbr, t_pipe_cmds *pipe_cmds);

#endif