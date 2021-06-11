#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if(s1[i] > s2[i])
			return (1);
		i++;
	}
	if (ft_strlen(s1) == ft_strlen(s2))
		return (0);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	else
		return(1);
}
