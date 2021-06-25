#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*haystack;
	unsigned char	needle;

	i = 0;
	haystack = (unsigned char *) s;
	needle = (unsigned char) c;
	while (i < n)
	{
		if (haystack[i] == needle)
			return ((void *) haystack + i);
		i++;
	}
	return (NULL);
}
