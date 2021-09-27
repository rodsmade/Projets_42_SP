#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

unsigned int	print_char(va_list args_list);
unsigned int	convert_format(const char *formatStr, va_list args_list);
unsigned int	print_int(va_list args_list);
unsigned int	print_char(va_list args_list);

int	ft_printf(const char *formatString, ...)
{
	unsigned int	write_count;
	va_list			args_list;

	// faz a lista apontar pro primeiro argumento da função;
	// o seja: inicializa args_list;
	va_start(args_list, formatString);
	write_count = 0;
	while (*formatString)
	{
		if (*formatString != '%')
			write_count += write(1, formatString, 1);
		else
			// eu tenho que passar a lista ou o endereço da lista pra dentro dessa de conversão
			write_count += convert_format(++formatString, args_list);
		formatString++;
	}
	va_end(args_list);
	return (write_count);
}

unsigned int	convert_format(const char *formatStr, va_list args_list)
{
	if (*formatStr == 'i')
		return (print_int(args_list));
	if (*formatStr == 'c')
		return (print_char(args_list));
	return (0);
}

unsigned int	print_char(va_list args_list)
{
	int	n;

	n = va_arg(args_list, int);
	return (write(1, &n, 1));
}

unsigned int	print_int(va_list args_list)
{
	int	n;

	n = va_arg(args_list, int);
	// converts to ascii
	n += 48;
	return (write(1, &n, 1));
}

int main()
{
	// print_ints(5, 'a', 'b', 'x');
	ft_printf("Teste: %i\n", 9);
	return (0);
}