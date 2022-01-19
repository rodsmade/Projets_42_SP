/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 20:45:34 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	free_stack(t_dbl_list_i *lst)
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
	free (lst);
}

void	print_stacks(t_stacks *stacks)
{
	int	i;
	t_dbl_list_i	*pivot;

	// printa stack a
	pivot = stacks->stack_a;
	i = -1;
	printf("stack a:\t(size: %i)\n", stacks->size_a);
	while (++i < stacks->size_a)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	// printa stack b
	pivot = stacks->stack_b;
	i = -1;
	printf("stack b:\t(size: %i)\n", stacks->size_b);
	while (++i < stacks->size_b)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_stacks		stacks;
	int				i;

	if (argc < 2)
		return (0);
	// cria stack a
	stacks.stack_a = NULL;
	i = 0;
	while (++i < argc)
		ft_dbl_lst_i_add_back(&stacks.stack_a, ft_dbl_lst_i_new(ft_atoi(argv[i])));
	stacks.size_a = ft_dbl_lst_i_size(stacks.stack_a);
	// cria stack b
	stacks.stack_b = NULL;
	ft_dbl_lst_i_add_back(&stacks.stack_b, ft_dbl_lst_i_new(42));
	ft_dbl_lst_i_add_back(&stacks.stack_b, ft_dbl_lst_i_new(24));
	stacks.size_b = ft_dbl_lst_i_size(stacks.stack_b);
	// printa as stacks
	print_stacks(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	reverse_rotate_ab(&stacks);
	print_stacks(&stacks);
	// dá free nas stacks
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}