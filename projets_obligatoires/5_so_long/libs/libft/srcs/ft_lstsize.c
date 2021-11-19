/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:54:49 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/06 10:54:50 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count_items;

	if (lst == NULL)
		return (0);
	count_items = 1;
	while (lst->next != NULL)
	{
		count_items++;
		lst = lst->next;
	}
	return (count_items);
}
