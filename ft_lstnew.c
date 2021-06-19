#include "libft.h"

t_list	*ft_lstnew(void *content);
// Parameters #1. The content to create the new element with.
// Return value The new element.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new
// element. The variable ’content’ is initialized
// with the value of the parameter ’content’. The
// variable ’next’ is initialized to NULL.
