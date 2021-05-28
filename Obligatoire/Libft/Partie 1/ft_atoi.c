#include "libft.h"
int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	signal;

	signal = 1;
	number = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' && ft_isdigit(nptr[i + 1])) || ft_isdigit(nptr[i]))
	{
		if (nptr[i] == '-')
		{
			signal *= -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			number = (nptr[i] - '0') + (number * 10);
			i++;
		}
	}
	return (number * signal);
}
