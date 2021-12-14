/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:10 by roaraujo          #+#    #+#             */
/*   Updated: 2021/09/18 10:51:48 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
/**
 * Returns the length of a valid string
*/
{
	int	qtd_caracteres;

	qtd_caracteres = 0;
	while (*s)
	{
		qtd_caracteres++;
		s++;
	}
	return (qtd_caracteres);
}

char	*ft_strdup(const char *s)
/**
 * duplicates one string into another. allocates memory using malloc.
*/
{
	unsigned int	strlength;
	char			*newstr;
	unsigned int	i;

	strlength = ft_strlen(s);
	newstr = malloc((strlength + 1) * sizeof(const char));
	if (newstr == NULL)
		return (NULL);
	newstr[strlength] = '\0';
	i = 0;
	while (i < strlength)
	{
		((char *) newstr)[i] = ((char *) s)[i];
		i++;
	}
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
/**
 * concatenates two strings of fixed length into one.
 * allocates memory using malloc.
*/
{
	char	*joint;
	int		i;
	int		length_s1;
	int		length_s2;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	joint = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++i])
		joint[i + length_s1] = s2[i];
	joint[length_s1 + length_s2] = '\0';
	free((char *)s1);
	return (joint);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
/**
 * copies (up to size bytes) the content of one string (src) into another (dst).
 * overwrites the contents of dst.
*/
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	contains_nl(char *string)
/**
 * scans a string for single line character (\n).
 * if found, returns its position (>= 0).
 * otherwise, returns -1.
*/
{
	int	i;

	if (!string)
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
