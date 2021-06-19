#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// Parameters #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// #3. The adress of the function used to delete the
// content of an element if needed.
// Return value The new list. NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed
