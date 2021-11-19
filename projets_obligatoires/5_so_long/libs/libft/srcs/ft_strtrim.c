/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:36 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/06 10:55:37 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i - 1]) && i)
		i--;
	return (ft_substr(s1, 0, i));
}
