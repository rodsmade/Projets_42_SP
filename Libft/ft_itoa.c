#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
	int qtd_caracteres;

	qtd_caracteres = 0;
	while (*s)
	{
		qtd_caracteres++;
		s++;
	}
	return (qtd_caracteres);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;
	int		length_s1;
	int		length_s2;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	joint = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++i])
		joint[i + length_s1] = s2[i];
	joint[length_s1 + length_s2] = '\0';
	return (joint);
}

static size_t is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t count_digits(size_t n)
{
	unsigned int digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
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

char	*ft_itoa(int n)
{
	char			*result;
	long int		big_n;
	unsigned int	i;

	// // tratar quando n = 0 pqp
	// if (n == 0)
		// return ("0");
	big_n = n;
	if (is_negative(n))
		big_n *= -1;
	// contar exatamente a qtd de dígitos p/ n alocar memória em excesso
	result = malloc((is_negative(n) + count_digits(big_n) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (big_n > 0)
	{
		// 2147483647
		result[i] = (big_n / ft_power(10, (count_digits(big_n) - 1))) + '0';
		big_n = big_n - (result[i] - '0') * ft_power(10, (count_digits(big_n) - 1));
		i++;
	}
	result[i] = '\0';
	if (is_negative(n))
		result = ft_strjoin("-", result);
	return (result);
}

#include <stdio.h>
int    main(void)
{
    printf("%s\n", ft_itoa(1));
    printf("%s\n", ft_itoa(15454));
    printf("%s\n", ft_itoa(2));
    printf("%s\n", ft_itoa(123123));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-123123));
    printf("%s\n", ft_itoa(-2147483647));
    printf("%s\n", ft_itoa(-2147483648));
    return (0);
}