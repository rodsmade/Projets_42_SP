#include "libft.h"

int	ft_lstsize(t_list *lst)
// Parameters #1. The beginning of the list.
// Return value Length of the list.
// External functs. None
// Description Counts the number of elements in a list.
{
	int	count_items;

	if (lst == NULL)
		return (0);
	count_items = 1;
	while(lst->next != NULL)
	{
		count_items++;
		lst = lst->next;
	}
	return (count_items);
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_list	**list_beginning;
// 	t_list	*ptr_head;
// 	// list_beginning = &ptr_head;
// 	t_list	element1;
// 	ptr_head = &element1;
// 	t_list	element2;
// 	t_list	element3;
// 	// t_list	element4;
// 	element1.content = (void *) "im the first element of the list";
// 	element1.next = &element2;
// 	element2.content = (void *) "im the second element of the list";
// 	element2.next = &element3;
// 	element3.content = (void *) "im the third element of the list";
// 	element3.next = NULL;
// 	// element4.content = (void *) "fourth element of the list";
// 	// element4.next = NULL;
// 	printf("tamanho da lista: %i\n", ft_lstsize(ptr_head));
// 	return (0);
// }