/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:06 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/06 10:55:09 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((char *) dest)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	return (dest);
}
