#include <stdio.h>

int	ft_printf(const char *formatString, ...)
{
	unsigned int	write_count;

	write_count = 0;
	while (*formatString)
	{
		if (*formatString == '%')
			write_count += convert_format(formatString, write_count);
		else
			write_count += write(1, formatString, 1);
		formatString++;
	}
}

unsigned int	convert_format(const char *formatString, unsigned int count)
{
	if (*format_string == 'c')
		print_char(formatString, count);
	if (*format_string == 's')
		print_string(formatString, count);
	if (*format_string == 'p')
		print_pointer(formatString, count);
	if (*format_string == 'd')
		print_double(formatString, count);
	if (*format_string == 'i')
		print_int(formatString, count);
	if (*format_string == 'u')
		print_udecimal(formatString, count);
	if (*format_string == 'x')
		print_uhex_lowercase(formatString, count);
	if (*format_string == 'X')
		print_uhex_uppercase(formatString, count);
	if (*format_string == '%')
		print_percent_sign(formatString, count);
}