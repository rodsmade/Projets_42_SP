#include "libft.h"

static long int	ft_power(int nb, int power);
static char		*ft_left_trim(char const *s1, char const c);

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
	result = ft_left_trim(result, '0');
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

static char	*ft_left_trim(char const *s1, char const c)
{
	char			*trim;
	int				i;
	unsigned int	length;

	length = ft_strlen(s1);
	trim = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	// size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
	if (ft_strlcpy(trim, s1, length) != length)
		return (NULL);
	i = 0;
	while (trim[0] == c)
	{
		trim = (char *) ft_memmove(trim, trim + 1, ft_strlen(trim) - 1);
		trim[length - 1 - i] = '\0';
		i++;
	}
	return (trim);
}
