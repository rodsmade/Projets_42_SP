#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	i = 0;
	if (dstlen < size)
	{
		while ((i + dstlen) < (size - 1) && src[i])
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
	}
	return (dstlen + srclen);
}
