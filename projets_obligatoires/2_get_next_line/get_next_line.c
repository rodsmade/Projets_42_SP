/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:04 by roaraujo          #+#    #+#             */
/*   Updated: 2021/09/18 10:41:14 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*free_n_null(char **s1, char **s2, char **s3)
/**
 * frees up allocated memory and set pointers to NULL
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
 * Everything else inside the buffer past the first \n found
 * is saved in the static variable `rest`. This guarantees
 * that the beginning of the next line is not lost between
 * function calls.
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
 * Wraps up the execution of get_next_line. Frees memory if need be,
 * then ties up the current read line and stores what's left from the buffer
 * in the static variable `rest` so as to resume the reading of the file
 * in the next function call.
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

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			chars_read;

	// initialize variables
	if (!rest)
		rest = ft_strdup("");
	line = ft_strdup(rest);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	chars_read = BUFFER_SIZE;

	// loop using read() as long as no \n is found
	while (chars_read == BUFFER_SIZE && !(contains_nl(line) >= 0))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		
		// terminate execution if file reading goes awry
		if (chars_read < 0)
			return (free_n_null(&line, &rest, &buffer));
		buffer[chars_read] = '\0';

		// concatenates buffer read with the line that's being built up
		line = ft_strjoin(line, buffer);
	}
	return (return_line(&rest, &buffer, &line, chars_read));
}
