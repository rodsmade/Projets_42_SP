#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*allocdmem;

	if (nmemb == 0 || size == 0)
		return (NULL);
	allocdmem = (void *) malloc (nmemb * size);
	if (allocdmem == NULL)
		return (NULL);
	ft_bzero(allocdmem, nmemb * size);
	return (allocdmem);
}
