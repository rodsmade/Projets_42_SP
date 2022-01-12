/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:54:09 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/11 21:03:56 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocdmem;

	allocdmem = (void *) malloc (nmemb * size);
	if (allocdmem == NULL)
		return (NULL);
	ft_bzero(allocdmem, nmemb * size);
	return (allocdmem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}

char	*ft_slashcat(const char *str1, const char *str2)
{
	char	*concat;
	int		i;

	concat = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 2, sizeof(char));
	if (concat == NULL || str1 == NULL || str2 == NULL)
		return (NULL);
	i = 0;
	while (*str1)
	{
		concat[i] = *str1;
		str1++;
		i++;
	}
	concat[i++] = '/';
	while (*str2)
	{
		concat[i] = *str2;
		str2++;
		i++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	unsigned int	strlength;
	char			*newstr;

	strlength = ft_strlen(s);
	newstr = ft_calloc((strlength + 1), sizeof(const char));
	if (newstr == NULL)
		return (NULL);
	newstr = ft_memcpy(newstr, s, strlength);
	return (newstr);
}
