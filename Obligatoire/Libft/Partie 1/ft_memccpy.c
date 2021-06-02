#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
// The memccpy() function copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found.
// The memccpy() function returns a pointer to the next character in dest after c, or NULL if c was not found in the first n characters of src.
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (((char*) src)[i] != c)
			((char *) dest)[i] = ((char*) src)[i];
		else
			return (dest + 1);
		i++;
	}
	return (NULL);
}
