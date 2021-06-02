#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0)
		return (NULL);
	return (malloc (nmemb * size));
}
