// hasn't yet been tested!
#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
// size = SOURCE'S SIZE GODDANGIT not really
// size = amount of memory that dest occupies, whether fully-occupied (all filled in plus '\0' - that's an assumption) or otherwise.
// (man) Also note that strlcpy() and strlcat() only operate on true “C” strings. This means (...) for strlcat() both src and dst must be NUL-terminated.
{
	// dst will be null-terminated by strlcat if strlcat modifies dst. Strlcat does not modify dst if dst is already fully occupied.
	// dst is considered fully-occupied if no NUL is found in the first size - 1 bytes of dst (or if size is 0).
	// It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
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
	// scans string looking for a null character; the remaining [(size - 1) - strlen(dest)] in dest will be filled with what's in source;
	while (i < size - 1)
	{
		if (dst[i] == '\0')
			null_found = 1;
		i++;
	}
	if (size == 0 || !null_found)
		return ft_strlen(dst);	// BC IM ASSUMING IT >>>IS<<< NULL-TERMINATED BC MANUAL SAYS SO
	else if (null_found)
	{
		remainder = (size - 1) - ft_strlen(dst);
		// while there are chars left in dest or source, whichever comes first
		while(j < remainder || src[j])
		{
			dst[i + j] = src[j];
			j++;
			i++;
			chars_written++;
		}
		dst[chars_written] = '\0';
	}
	// So there are two cases in which dst will not be null-terminated by strlcat.
	// One is that dst is a null-terminated string of exactly size - 1 bytes, in which case it is not modified and continues to be null-terminated.
	// The second case is that dst was not null-terminated initially, and in that case it will still be unterminated after the call to strlcat.
	// (man) The strlcpy() and strlcat() functions return the total length of the string they tried to create. For strlcat() that means the initial length of dst plus the length of src.
	// return = min(size, strlen(dst)) + strlen(src)
	return(ft_strlen(dst) + chars_written);
}
