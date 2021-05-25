#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
	unsigned int	i;
	unsigned int	chars_written;

	i = 0;
	chars_written = 0;
	if (*src == '\0')
		return (0);
	// TODO: testar! troquei *src por src[i]
	while (src[i] && i < dest_size - 1)
	{
		dst[i] = src[i];
		chars_written++;
		i++;
	}
	dst[chars_written] = '\0';
	return (ft_strlen(src));
}

#include <bsd/string.h>
#include <stdio.h>

int main()
{
	char *source1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *source2 = "abcdefghijklmnopqrstuvwxyz";
	char dest1[26];
	char dest2[26];
	size_t dest_size = 229;
	
	printf("resultado1 (normal)    : %li\n", strlcpy(dest1, source1, dest_size));
	printf("resultado2 (ft_strlcpy): %li\n", ft_strlcpy(dest2, source2, dest_size));
	printf("dest1: %s\n", dest1);
	printf("dest2: %s\n", dest2);
	return 0;
}