#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
// size = SOURCE'S SIZE GODDANGIT
//  Also note that strlcpy() and strlcat() only operate on true “C” strings. This means (...) for strlcat() both src and dst must be NUL-terminated. (man)
{
	// dst will be null-terminated by strlcat if strlcat modifies dst. Strlcat does not modify dst if dst is already fully occupied.
	// dst is considered fully-occupied if no NUL is found in the first size - 1 bytes of dst (or if size is 0).
	// It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
	int i = 0;
	int j = 0;
	int null_found = 0;

	if (size == 0)
		return ft_strlen(dest);	// BC IM ASSUMING IT >>>IS<<< NULL-TERMINATED
	while (i < size)
	{
		// faz oq?
		if (dest[i] == '\0')
			null_found = 1;
		i++;
	}
	if (null_found)
	{
		// do things
		while(source[j])
			dest[]
	}
	else
	{

	}
	// So there are two cases in which dst will not be null-terminated by strlcat.
	// One is that dst is a null-terminated string of exactly size - 1 bytes, in which case it is not modified and continues to be null-terminated.
	// The second case is that dst was not null-terminated initially, and in that case it will still be unterminated after the call to strlcat.

	// return = min(size, strlen(dst)) + strlen(src)

	return;
}