#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
// Parameters #1. The address of a pointer to the first link of
// a list.
// #2. The address of a pointer to the element to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the element ’new’ at the beginning of the
// list.
{
	new->next = *lst;
	lst = &new;
	return;
}

#include <stdio.h>
int main(void)
{
	// t_list	**list_beginning;
	t_list	*ptr_head;
	// list_beginning = &ptr_head;
	t_list	element1;
	ptr_head = &element1;
	t_list	element2;
	t_list	element3;
	t_list	element4;
	element1.content = (void *) "im the first element of the list";
	element1.next = &element2;
	element2.content = (void *) "im the second element of the list";
	element2.next = &element3;
	element3.content = (void *) "im the third element of the list";
	element3.next = NULL;
	element4.content = (void *) "ill become the header element of the list";
	element4.next = NULL;
	printf("inicio da lista:\t%s\n", (char *) ptr_head->content);
	ft_lstadd_front(&ptr_head, &element4);
	printf("novo inicio da lista:\t%s\n", (char *) ptr_head->content);
	return (0);
}