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

#include "libft.h"

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
