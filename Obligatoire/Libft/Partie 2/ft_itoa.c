#include "libft.h"

void	ft_swap(char *a, char *b);
void	ft_rev_int_tab(char *tab);

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	big_n;
	int				needle;

	big_n = n;
	needle = 0;
	result = malloc(11 * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		big_n *= -1;
		needle++;
	}
	while (needle < 10)
	{
		result[needle] = (big_n % 10) + '0';
		big_n = big_n / 10;
		needle++;
	}
	while (++count != 42 && n != 0)
		n = n / 10;
}

void	ft_swap(char *a, char *b)
{
	int guarda_rapidin;

	guarda_rapidin = *a;
	*a = *b;
	*b = guarda_rapidin;
}

void	ft_rev_int_tab(char *tab)
{
	int count;

	count = 0;
	while (count++ <= (size / 2) + 1)
	{
		ft_swap(tab, tab + size - count);
		tab++;
		size--;
	}
}