/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/27 16:24:25 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return ;
}

static void	free_stack(t_dbl_list_i *lst)
{
	t_dbl_list_i	*aux;

	if (lst == NULL)
		return ;
	while (lst->next)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
	free(lst);
	return ;
}

void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	return ;
}

void	error_exit(t_stacks *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	checks_duplicates(t_stacks *stacks)
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

void	find_both_ends_of_list(t_stacks *stacks)
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
	printf("smallest: %i, biggest: %i\n", stacks->smallest_element, stacks->biggest_element);
	return ;
}

void	validate_input(char *argv[], t_stacks *stacks)
{
	int	i;

	initialise(stacks);
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
	ft_putendl_fd("all args passed check", 1);
	if (!checks_duplicates(stacks))
		error_exit(stacks);
	ft_putendl_fd("no duplicates found", 1);
	find_both_ends_of_list(stacks);
	return ;
}

void	sort(t_stacks *stacks)
{
	print_stacks(stacks);
	strategy_part_one(stacks);
	strategy_part_two(stacks);
	// strategy_part_three(stacks);
	print_stacks(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks		stacks;

	if (argc > 2)
	{
		validate_input(argv, &stacks);
		if (!is_sorted_asc(stacks.stack_a))
			sort(&stacks);
	}
	free_stacks(&stacks);
	return (0);
}
