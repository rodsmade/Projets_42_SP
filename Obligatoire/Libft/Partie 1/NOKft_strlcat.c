#include "libft.h"
size_t	strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	null_found;
	unsigned int	remainder;
	unsigned int	chars_written;

	i = 0;
	j = 0;
	null_found = 0;
	remainder = 0;
	chars_written = 0;
	while (i < size - 1)
	{
		if (dst[i] == '\0')
			null_found = 1;
		i++;
	}
	if (size == 0 || !null_found)
		return (ft_strlen(dst));
	else if (null_found)
	{
		remainder = (size - 1) - ft_strlen(dst);
		while (j < remainder || src[j])
		{
			dst[i + j] = src[j];
			j++;
			i++;
			chars_written++;
		}
		dst[chars_written] = '\0';
	}
	return (ft_strlen(dst) + chars_written);
}
