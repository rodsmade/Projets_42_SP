/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:42:27 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/20 21:07:37 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_dbl_list_i	*first_element;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
	first_element = ft_dbl_lst_i_first(*lst);
	first_element->prev = new;
	new->prev = NULL;
	new->next = first_element;
	*lst = new;
	return ;
}
