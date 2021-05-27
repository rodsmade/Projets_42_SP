#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
// The  memchr()  function scans the initial n bytes of the memory area pointed to by s for the first instance of c.
// Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.
// The memchr() and memrchr() functions return a pointer to the matching byte or NULL if the character does not occur in the given memory area.
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
