/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:15:13 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/23 14:33:45 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// -- INCLUDE -----------------------------------------------------------------|
//  Libft
# include "libft.h"
// exit(), malloc(), free()
# include <stdlib.h>
// write(), read()
# include <unistd.h>
// macro INT_MAX
# include <limits.h>

// -- TYPEDEFS (structs) ------------------------------------------------------|
typedef struct s_dbl_list_i
{
	int					content;
	struct s_dbl_list_i	*prev;
	struct s_dbl_list_i	*next;
}					t_dbl_list_i;

typedef struct s_stacks
{
	t_dbl_list_i	*stack_a;
	t_dbl_list_i	*stack_b;
}					t_stacks;

// -- PROTOTYPES --------------------------------------------------------------|
// utils_double_list_1.c
t_dbl_list_i	*ft_dbl_lst_i_new(int content);
int				ft_dbl_lst_i_size(t_dbl_list_i *lst);
t_dbl_list_i	*ft_dbl_lst_i_last(t_dbl_list_i *lst);
t_dbl_list_i	*ft_dbl_lst_i_first(t_dbl_list_i *lst);

// utils_double_list_2.c
void			ft_dbl_lst_i_add_back(t_dbl_list_i **lst, t_dbl_list_i *new);
void			ft_dbl_lst_i_add_front(t_dbl_list_i **lst, t_dbl_list_i *new);

// utils_operations_push.c
void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);

// utils_operations_reverse_rotate.c
void			reverse_rotate_a(t_stacks *stacks);
void			reverse_rotate_b(t_stacks *stacks);
void			reverse_rotate_ab(t_stacks *stacks);

// utils_operations_rotate.c
void			rotate_a(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			rotate_ab(t_stacks *stacks);

// utils_operations_swap.c
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			swap_ab(t_stacks *stacks);

// utils_sorting.c
void	sort_three_elements_b(t_stacks *stacks);

// push_swap.c
void			free_stack(t_dbl_list_i *lst);
void			print_stacks(t_stacks *stacks);
void	print_stacks_ptrs(t_stacks *stacks);

#endif