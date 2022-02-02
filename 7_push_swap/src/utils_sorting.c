/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:17:07 by roaraujo          #+#    #+#             */
/*   Updated: 2022/02/02 03:56:35 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * top = list's first element
 * ascending order = ascending top down
 * an empty stack is considered unsorted
 */
int	is_sorted_asc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	if (!stack)
		return (0);
	pivot = stack;
	while (pivot->next != NULL)
	{
		if (pivot->content > pivot->next->content)
			return (0);
		pivot = pivot->next;
	}
	return (1);
}

/*
 * top = list's first element
 * descending order = descending top down
 * an empty stack is considered unsorted
 */
int	is_sorted_desc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	if (!stack)
		return (0);
	pivot = stack;
	while (pivot->next != NULL)
	{
		if (pivot->content < pivot->next->content)
			return (0);
		pivot = pivot->next;
	}
	return (1);
}
