#include "libft.h"
#include "printf.h"

unsigned int	print_char(va_list args_list);
unsigned int	convert_format(const char *formatStr, va_list args_list);
unsigned int	print_signed_decimal(va_list args_list);
unsigned int	print_char(va_list args_list);
unsigned int	print_string(va_list args_list);
unsigned int	print_hex(va_list args_list, char xcase);
unsigned int	print_percent_sign(void);

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
	if (*formatStr == 'i' || *formatStr == 'd')
		return (print_signed_decimal(args_list));
	if (*formatStr == 'c')
		return (print_char(args_list));
	if (*formatStr == 's')
		return (print_string(args_list));
	if (*formatStr == 'x' || *formatStr == 'X')
		return (print_hex(args_list, *formatStr));
	if (*formatStr == '%')
		return (print_percent_sign());
	return (0);
}

unsigned int	print_signed_decimal(va_list args_list)
{
	char	*int_to_alpha;

	int_to_alpha = ft_itoa(va_arg(args_list, int));
	ft_putstr_fd(int_to_alpha, 1);
	return (ft_strlen(int_to_alpha));
}

unsigned int	print_char(va_list args_list)
{
	char	c;

	c = va_arg(args_list, int);
	return (write(1, &c, 1));
}

unsigned int	print_string(va_list args_list)
{
	char	*string;
	int		chars_written;

	string = va_arg(args_list, char *);
	chars_written = 0;
	while (*string)
	{
		chars_written += write(1, string, 1);
		string++;
	}
	return (chars_written);
}

unsigned int	print_hex(va_list args_list, char xcase)
{
	char	*int_to_hex;
	int		chars_written;

	chars_written = 0;
	if (xcase == 'x')
		int_to_hex = ft_itoh(va_arg(args_list, int), HEXALOW);
	else
		int_to_hex = ft_itoh(va_arg(args_list, int), HEXAUPP);
	while (*int_to_hex)
	{
		chars_written += write(1, int_to_hex, 1);
		int_to_hex++;
	}
	return (chars_written);
}

unsigned int	print_percent_sign(void)
{
	return (write(1, "%", 1));
}

int main()
{
	// print_ints(5, 'a', 'b', 'x');
	ft_printf("Teste: %% aaaaaa %% %% %s\ne air funcionar ???\n", "eheita jesus");
	return (0);
}
