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
	if ((nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			signal *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - '0') + (number * 10);
		i++;
	}
	return (number * signal);
}
