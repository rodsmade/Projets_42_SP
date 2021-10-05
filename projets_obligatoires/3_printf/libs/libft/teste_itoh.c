#include "libft.h"
#include <stdio.h>

char	*ft_itoh(unsigned int n, char *base)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	while (n /= b_len)
		size++;
	if (!(a = (char *)malloc(size + 1)))
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}

int main ()
{
	printf("resultado: %s\n", ft_itoh(0, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(-1, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(-2, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(-3, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(1, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(2, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(3, "0123456789abcdef"));
	// printf("resultado: %s\n", ft_itoh(2147483648, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(2147483647, "0123456789abcdef"));
	// printf("resultado: %s\n", ft_itoh(-2147483648, "0123456789abcdef"));
	printf("resultado: %s\n", ft_itoh(-2147483647, "0123456789abcdef"));
	printf("****************************\n");
	printf("resultado: %x\n", 0);
	printf("resultado: %x\n", -1);
	printf("resultado: %x\n", -2);
	printf("resultado: %x\n", -3);
	printf("resultado: %x\n", 1);
	printf("resultado: %x\n", 2);
	printf("resultado: %x\n", 3);
	// printf("resultado: %x\n", 2147483648);
	printf("resultado: %x\n", 2147483647);
	// printf("resultado: %x\n", -2147483648);
	printf("resultado: %x\n", -2147483647);
	return 0;
}