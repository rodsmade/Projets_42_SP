#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
/* The  memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match,
or be greater than the first n bytes of s2.
For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2.
If n is zero, the return value is zero.*/
{
	unsigned char	*this;
	unsigned char	*that;
	unsigned int	i;

	this = (unsigned char *) s1;
	that = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*this != *that)
			return (*this - *that);
		this++;
		that++;
		i++;
	}
	return (0);
}
