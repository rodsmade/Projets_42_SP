#include <stdio.h>
#include <stdarg.h>

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
		{
			// eu acho que tenho que passar a lista ou o endereço da lista pra dentro dessa de conversão
			write_count += convert_format(formatString, write_count);
		}
		formatString++;
	}
	va_end(args_list);
	return (write_count);
}

unsigned int	convert_format(const char *formatString, unsigned int count)
{
	if (*formatString == 'c')
		count += print_char(formatString, count);
	if (*formatString == 's')
		count += print_string(formatString, count);
	if (*formatString == 'p')
		count += print_pointer(formatString, count);
	if (*formatString == 'd')
		count += print_double(formatString, count);
	if (*formatString == 'i')
		count += print_int(formatString, count);
	if (*formatString == 'u')
		count += print_udecimal(formatString, count);
	if (*formatString == 'x')
		count += print_uhex_lowercase(formatString, count);
	if (*formatString == 'X')
		count += print_uhex_uppercase(formatString, count);
	if (*formatString == '%')
		count += print_percent_sign(formatString, count);
	return (count);
}