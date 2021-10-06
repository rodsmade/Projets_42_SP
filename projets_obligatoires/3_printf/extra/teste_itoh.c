#include "libft.h"
#include <stdio.h>

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