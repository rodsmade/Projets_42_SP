#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	// vai precisar da itoa
	// joga resultado itoa em ft_putstr_fd
	ft_putstr_fd(ft_itoa(n), fd);
}

#include <stdio.h>
int main()
{
	int n = 95;
	printf("Entrada: %i\n", n);
	write(1, "Saida: ", 7);
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
	return (0);
}