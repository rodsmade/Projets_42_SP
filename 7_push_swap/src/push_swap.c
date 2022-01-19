/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 16:20:03 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

typedef struct s_dbl_list_i
{
	int					content;
	struct s_dbl_list_i	*prev;
	struct s_dbl_list_i	*next;
}					t_dbl_list_i;

typedef struct s_stacks
{
	t_dbl_list_i	*stack_a;
	int				size_a;
	t_dbl_list_i	*stack_b;
	int				size_b;
}					t_stacks;

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
		*lst = new;
	else
	{
		last_element = ft_dbl_lst_i_last(*lst);
		last_element->next = new;
		new->next = NULL;
	}
}

void	ft_dbl_lst_i_add_front(t_dbl_list_i **lst, t_dbl_list_i *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

void	free_stack(t_dbl_list_i *lst)
{
	t_dbl_list_i	*aux;

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
	printf("stack a:\n");
	while (++i < stacks->size_a)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	// printa stack b
	pivot = stacks->stack_b;
	i = -1;
	printf("stack b:\n");
	while (++i < stacks->size_b)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	return ;
}

void	swap_a(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (stacks->size_a < 2)
		return ;
	new_first = stacks->stack_a->next;
	new_second = stacks->stack_a;
	stacks->stack_a = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("sa", 1);
	return ;
}

void	swap_b(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (stacks->size_b < 2)
		return ;
	new_first = stacks->stack_b->next;
	new_second = stacks->stack_b;
	stacks->stack_b = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("sb", 1);
	return ;
}

void	swap_ab(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (stacks->size_a < 2)
		return ;
	new_first = stacks->stack_a->next;
	new_second = stacks->stack_a;
	stacks->stack_a = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	new_first = stacks->stack_b->next;
	new_second = stacks->stack_b;
	stacks->stack_b = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("ss", 1);
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
	swap_ab(&stacks);
	print_stacks(&stacks);
	// dá free nas stacks
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}