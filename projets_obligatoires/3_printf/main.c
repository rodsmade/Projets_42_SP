#include <stdio.h>
#include "printf.h"

int main()
{
	char	*ptr;
	char	aaa = '*';
	ptr = &aaa;

	ft_printf("------------------------------------------------------\nQue comecem os testes:\n");
	ft_printf("i: %i\t\t\t--\tinput: 42\n", 42);
	ft_printf("d: %d\t\t\t--\tinput: 42\n", 42);
	ft_printf("u: %u\t\t\t--\tinput: -42\n", -42);
	ft_printf("c: %c\t\t\t--\tinput: 42\n", 42);
	ft_printf("s: %s\t--\tinput: Quarenta e dois\n", "Quarenta e dois");
	ft_printf("x: %x\t\t\t--\tinput: 42\n", 42);
	ft_printf("X: %X\t\t\t--\tinput: 42\n", 42);
	ft_printf("p: %p\t--\tinput: um ponteiro sla\n", ptr);
	ft_printf("percent: %%\t\t--\tinput: void\n");
	return (0);
}
