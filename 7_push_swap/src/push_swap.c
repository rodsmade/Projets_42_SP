/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/02/02 04:08:06 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_duplicates(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;
	t_dbl_list_i	*duplicate;

	pivot = stacks->stack_a;
	while (pivot->next != NULL)
	{
		duplicate = pivot->next;
		while (duplicate->next != NULL)
		{
			if (pivot->content == duplicate->content)
				return (0);
			duplicate = duplicate->next;
		}
		if (pivot->content == duplicate->content)
			return (0);
		pivot = pivot->next;
	}
	if (pivot->content == pivot->prev->content)
		return (0);
	return (1);
}

static void	find_both_ends_of_list(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;

	stacks->biggest_element = stacks->stack_a->content;
	stacks->smallest_element = stacks->stack_a->content;
	pivot = stacks->stack_a->next;
	while (pivot)
	{
		if (pivot->content > stacks->biggest_element)
			stacks->biggest_element = pivot->content;
		if (pivot->content < stacks->smallest_element)
			stacks->smallest_element = pivot->content;
		pivot = pivot->next;
	}
	return ;
}

static void	validate_input(char *argv[], t_stacks *stacks)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_isnumeric_s(argv[i]))
			error_exit(stacks);
		if (ft_atoli(argv[i]) > INT_MAX)
			error_exit(stacks);
		ft_dbl_lst_i_add_back(&stacks->stack_a,
			ft_dbl_lst_i_new(ft_atoi(argv[i])));
	}
	if (!check_for_duplicates(stacks))
		error_exit(stacks);
	find_both_ends_of_list(stacks);
	return ;
}

void	sort(t_stacks *stacks)
{
	//TODO: make a whole new mess again
	if (stacks->stack_a)
		ft_putendl_fd("WIP eheh", 1);
	return ;
}

int	main(int argc, char *argv[])
{
	t_stacks		stacks;

	initialise(&stacks);
	if (argc > 2)
	{
		validate_input(argv, &stacks);
		if (!is_sorted_asc(stacks.stack_a))
			sort(&stacks);
	}
	free_stacks(&stacks);
	return (0);
}
