/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:42:27 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 20:47:58 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbl_list_i	*ft_dbl_lst_i_new(int content)
{
	t_dbl_list_i	*newitem;

	newitem = malloc(sizeof(t_dbl_list_i));
	newitem->content = content;
	newitem->prev = NULL;
	newitem->next = NULL;
	return (newitem);
}

int	ft_dbl_lst_i_size(t_dbl_list_i *lst)
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

t_dbl_list_i	*ft_dbl_lst_i_last(t_dbl_list_i *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_dbl_lst_i_add_back(t_dbl_list_i **lst, t_dbl_list_i *new)
{
	t_dbl_list_i	*last_element;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		last_element = ft_dbl_lst_i_last(*lst);
		last_element->next = new;
		new->prev = last_element;
		new->next = NULL;
	}
}

void	ft_dbl_lst_i_add_front(t_dbl_list_i **lst, t_dbl_list_i *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
	new->prev = NULL;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
	return ;
}
