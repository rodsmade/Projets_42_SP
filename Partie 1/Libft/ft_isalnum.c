int	ft_isalnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
			return (1);
	return (0);
}

#include <ctype.h>
#include <stdio.h>

