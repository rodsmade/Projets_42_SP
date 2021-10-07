#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char	*ptr;
	char	aaa = '*';
	ptr = &aaa;

	ft_printf("------------------------------------------------------\nQue comecem os testes:\n");
	
	// // TESTE PRINCIPAL PEBA
	// ft_printf("i: %i\t\t\t--\tinput: 42\n", 42);
	// ft_printf("d: %d\t\t\t--\tinput: 42\n", 42);
	// ft_printf("u: %u\t\t\t--\tinput: -42\n", -42);
	// ft_printf("c: %c\t\t\t--\tinput: 42\n", 42);
	// ft_printf("s: %s\t--\tinput: Quarenta e dois\n", "Quarenta e dois");
	// ft_printf("x: %x\t\t\t--\tinput: 42\n", 42);
	// ft_printf("X: %X\t\t\t--\tinput: 42\n", 42);
	// ft_printf("p: %p\t--\tinput: um ponteiro sla\n", ptr);
	// ft_printf("percent: %%\t\t--\tinput: void\n");

	// // TESTE DE PONTEIRO NULL
	// int meu_result;
	// int result_printf;

	// meu_result = ft_printf("ft_printf: NULL %s NULL\n", NULL);
	// result_printf = printf("   printf: NULL %s NULL\n", NULL);
	// printf("Meu result: %i\nResult printf: %i\n", meu_result, result_printf);

	// // TESTE DE PONTEIRO
	// int	*potero;
	// int meu_result;
	// int result_printf;

	// meu_result = ft_printf("%p\n", potero);
	// result_printf = printf("%p\n", potero);
	// printf("Meu result: %i\nResult printf: %i\n", meu_result, result_printf);

	// TESTE DE PONTEIRO = 0
	int meu_result;
	int result_printf;

	meu_result = ft_printf("%p\n", 0);
	result_printf = printf("%p\n", 0);
	printf("Meu result: %i\nResult printf: %i\n", meu_result, result_printf);

	return (0);
}
