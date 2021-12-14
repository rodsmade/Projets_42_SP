/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:04 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/07 00:12:52 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_n_null(char **s1, char **s2, char **s3);
static char	*copy_up_to_nl(char *string);
static char	*save_past_first_nl(char *source);
static char	*return_line(char **rest, char **buffer, char **line, int i);

char	*ft_get_next_line(int fd)
/**
 *	This function reads from a file descriptor and returns one line read
 *	per call, defined henceforth as a string ending in \n, unless EOF
 *	is reached and no \n is present, in which case all tha has been read
 *	is returned at once.
*/
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			chars_read;

	if (!rest)
		rest = ft_strdup("");
	line = ft_strdup(rest);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	chars_read = BUFFER_SIZE;
	while (chars_read == BUFFER_SIZE && !(contains_nl(line) >= 0))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_n_null(&line, &rest, &buffer));
		buffer[chars_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (return_line(&rest, &buffer, &line, chars_read));
}

static void	*free_n_null(char **s1, char **s2, char **s3)
/**
 *	frees up allocated memory and sets pointers to NULL
*/
{
	if (s1)
	{
		if (*s1)
			free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		if (*s2)
			free(*s2);
		*s2 = NULL;
	}
	if (s3)
	{
		if (*s3)
			free(*s3);
		*s3 = NULL;
	}
	return (NULL);
}

static char	*copy_up_to_nl(char *string)
/**
 * ties up the line up to the first \n found in the string.
*/
{
	char	*copy;
	int		nl_pos;

	nl_pos = contains_nl(string);
	if (!string)
		return (NULL);
	if (!(nl_pos >= 0))
		return (string);
	copy = malloc((nl_pos + 2) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy[nl_pos + 1] = '\0';
	ft_strlcpy(copy, string, nl_pos + 2);
	free(string);
	return (copy);
}

static char	*save_past_first_nl(char *source)
/**
 *	Everything else inside the buffer past the first \n found
 *	is saved in the static variable `rest`. This guarantees
 *	that the beginning of the next line is not lost between
 *	function calls.
*/
{
	char	*dest;
	int		nl_pos;
	int		strlen;

	nl_pos = contains_nl(source);
	if (!(nl_pos >= 0))
		return (NULL);
	dest = malloc(((strlen = ft_strlen(source)) - nl_pos) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[strlen - nl_pos - 1] = '\0';
	ft_strlcpy(dest, source + nl_pos + 1, strlen - nl_pos);
	return (dest);
}

static char	*return_line(char **rest, char **buffer, char **line, int i)
/**
 *	Wraps up the execution of ft_get_next_line. Frees memory if need be,
 *	then ties up the current read line to be returned,
 *	and stores what's left from the buffer in the static variable `rest`
 *	so as to have the beginning of the next line saved for the next function call.
*/
{
	if (i == 0)
	{
		free_n_null(rest, buffer, NULL);
		if (*line && **line)
			return (*line);
		return (free_n_null(line, NULL, NULL));
	}
	free_n_null(rest, buffer, NULL);
	*rest = save_past_first_nl(*line);
	*line = copy_up_to_nl(*line);
	return (*line);
}
