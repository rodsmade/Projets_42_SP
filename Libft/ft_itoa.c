#include "libft.h"

static long int	ft_power(int nb, int power);

char	*ft_itoa(int n)
{
	char		*result;
	long int	big_n;
	int			needle;

	big_n = n;
	if (n < 0)
		big_n *= -1;
	// 10 dígitos + 1 sinal + '\0'
	result = malloc(11 * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	// tratar quando n = 0 pqp
	if (n == 0)
		return ("0");
	needle = 0;
	while (needle < 10 || big_n > 0)
	{
		// 2147483647
		result[needle] = (big_n / ft_power(10, (9 - needle))) + '0';
		big_n = big_n - (result[needle] - '0') * ft_power(10, (9 - needle));
		needle++;
	}
	result[10] = '\0';
	while (result[0] == '0')
		result++;
	if (n < 0)
		result = ft_strjoin("-", result);
	return (result);
}

static long int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}
