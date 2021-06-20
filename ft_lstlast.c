#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
// Parameters #1. The beginning of the list.
// Return value Last element of the list.
// External functs. None
// Description Returns the last element of the list.
{
	if (lst->next == NULL)
		return lst;
	while (lst->next != NULL)
		lst++;
	return (lst);
}

#include <stdio.h>
int main(void)
{
	t_list	*ptr_head;
	t_list	element1;
	// t_list	element2;
	// t_list	element3;
	// t_list	element4;
	ptr_head = &element1;
	element1.content = (void *) "im the first element of the list";
	element1.next = NULL;
	// element2.content = (void *) "im the second element of the list";
	// element2.next = &element3;
	// element3.content = (void *) "im the third element of the list";
	// element3.next = &element4;
	// element4.content = (void *) "fourth element of the list";
	// element4.next = NULL;
	printf("último elemento da lista: %s\n", (char* ) ft_lstlast(ptr_head)->content);
	return (0);
}