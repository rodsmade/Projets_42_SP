#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*this;
	unsigned char	*that;
	unsigned int	i;

	this = (unsigned char *) s1;
	that = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*this != *that)
		{
			if (*this < *that)
				return (*this - *that);
			else
				return (*that - *this);
		}
		this++;
		that++;
		i++;
	}
	return (0);
}
