#include "libft.h"

char	*ft_itoh(unsigned int n, char *base_str)
{
	unsigned int	int_to_hex;
	size_t			digits;
	int				base;
	char			*result;

	base = ft_strlen(base_str);
	int_to_hex = n;
	digits = 1;
	while (n /= base)
		digits++;
	if (!(result = (char *)malloc(digits + 1)))
		return (0);
	result[digits--] = '\0';
	while (int_to_hex > 0)
	{
		result[digits--] = base_str[int_to_hex % base];
		int_to_hex /= base;
	}
	if (digits == 0 && result[1] == '\0')
		result[0] = '0';
	return (result);
}
