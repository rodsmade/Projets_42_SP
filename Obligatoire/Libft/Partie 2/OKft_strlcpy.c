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
