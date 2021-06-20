#include "libft.h"

t_list	*ft_lstnew(void *content)
// Parameters #1. The content to create the new element with.
// Return value The new element.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new
// element. The variable ’content’ is initialized
// with the value of the parameter ’content’. The
// variable ’next’ is initialized to NULL.
{
	t_list	*newitem;

	newitem = malloc(sizeof(t_list));
	newitem->content = content;
	newitem->next = NULL;
	return (newitem);
}

// #include <stdio.h>
// int main()
// {
// 	t_list *newitem = ft_lstnew((void *) "Hello world?");
// 	printf("%s\n", (char *) newitem->content);
// 	return (0);
// }