/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:54:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/06 10:54:56 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*haystack;
	unsigned char	needle;

	i = 0;
	haystack = (unsigned char *) s;
	needle = (unsigned char) c;
	while (i < n)
	{
		if (haystack[i] == needle)
			return ((void *) haystack + i);
		i++;
	}
	return (NULL);
}
