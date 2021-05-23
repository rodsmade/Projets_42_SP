#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
	int	i = 0;

	while (*src && i < dest_size - 1)
	{
		dst[i] = src[i];
	}
	dst[dest_size - 1] = '\0';
	// size = length + 1 ('\0')
	// strlcpy takes the destination's size as a parameter and will not write more than that many bytes
	
	// The strlcpy() function returns the total length of the string it tried to create.
	// For strlcpy() that means the length of src.
	return (ft_strlen(src));
}

#include <string.h>

int main()
{
	char source[10];
	char *dest = "123456789";
	size_t dest_size = 10;
	strlcpy(dest, source, dest_size);
	return 0;
}