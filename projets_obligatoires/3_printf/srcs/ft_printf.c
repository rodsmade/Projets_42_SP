/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:56 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/08 11:42:29 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO: REMOVER DEPOIS E DEIXAR SÓ NO HEADER
typedef struct
{
	int	hash;
	int	zero;
	int	plus;
	int	dash;
	int	blank;
	int	precision;
	int	field_width;
} flags; 
flags	all_flags;

unsigned int	convert_format(const char *formatStr, va_list args_list);
int				capture_flags(const char *formatStr);
void			initialise_flags(void);
unsigned int	print_char(int arg);
unsigned int	print_percent_sign(void);
unsigned int	print_pointer(unsigned long int arg);
unsigned int	print_signed_decimal(int arg);
unsigned int	print_string(char *arg);
unsigned int	print_unsigned_decimal(unsigned int arg);
unsigned int	print_unsigned_hex(unsigned int arg, char xcase);


int	ft_printf(const char *formatString, ...)
{
	unsigned int	write_count;
	va_list			args_list;
	int				offset;

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
			initialise_flags();
			formatString++;
			offset = capture_flags(formatString);
			formatString += offset;
			write_count += convert_format(formatString, args_list);
		}
		formatString++;
	}
	va_end(args_list);
	return (write_count);
}

void			initialise_flags(void)
{
	all_flags.blank = 0;
	all_flags.dash = 0;
	all_flags.field_width = 0;
	all_flags.hash = 0;
	all_flags.plus = 0;
	all_flags.precision = 0;
	all_flags.zero = 0;
	return ;
}

unsigned int	convert_format(const char *formatStr, va_list args_list)
{
	int	offset;

	offset = capture_flags(formatStr);
	if (formatStr[offset] == 'i' || formatStr[offset] == 'd')
		return (print_signed_decimal(va_arg(args_list, int)));
	if (formatStr[offset] == 'u')
		return (print_unsigned_decimal(va_arg(args_list, unsigned int)));
	if (formatStr[offset] == 'c')
		return (print_char(va_arg(args_list, int)));
	if (formatStr[offset] == 's')
		return (print_string(va_arg(args_list, char *)));
	if (formatStr[offset] == 'x' || formatStr[offset] == 'X')
		return (print_unsigned_hex(va_arg(args_list, unsigned int), formatStr[offset]));
	if (formatStr[offset] == 'p')
		return (print_pointer(va_arg(args_list, unsigned long int)));
	if (formatStr[offset] == '%')
		return (print_percent_sign());
	return (offset);
}

int				capture_flags(const char *formatStr)
{
	int	i;

	i = 0;
	while (ft_strchr(FLAGS, formatStr[i]))
	{
		if (formatStr[i] == '#')
			all_flags.hash = 1;
		i++;
	}
	return (i);
}

unsigned int	print_signed_decimal(int arg)
{
	char	*int_to_alpha;
	int		length;
	// ao invés de guardar em um int, guarda em um struct 

	int_to_alpha = ft_itoa(arg);
	ft_putstr_fd(int_to_alpha, 1);
	length = ft_strlen(int_to_alpha);
	free(int_to_alpha);
	return (length);
}

unsigned int	print_unsigned_decimal(unsigned int arg)
{
	char	*int_to_alpha;
	int		length;

	int_to_alpha = ft_uitoa(arg);
	ft_putstr_fd(int_to_alpha, 1);
	length = ft_strlen(int_to_alpha);
	free(int_to_alpha);
	return (length);
}

unsigned int	print_char(int arg)
{
	return (write(1, &arg, 1));
}

unsigned int	print_string(char *arg)
{
	unsigned int	chars_written;
	int				i;

	if (arg == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	chars_written = 0;
	i = 0;
	while (arg[i])
	{
		chars_written += write(1, &arg[i], 1);
		i++;
	}
	return (chars_written);
}

unsigned int	print_unsigned_hex(unsigned int arg, char xcase)
{
	char			*int_to_hex;
	unsigned int	chars_written;
	int				i;

	chars_written = 0;
	if (all_flags.hash == 1)
	{
		chars_written += write(1, "0", 1);
		chars_written += write(1, &xcase, 1);
	}
	if (xcase == 'x')
		int_to_hex = ft_uitohex(arg, HEXALOW);
	else
		int_to_hex = ft_uitohex(arg, HEXAUPP);
	i = 0;
	while (int_to_hex[i])
	{
		chars_written += write(1, &int_to_hex[i], 1);
		i++;
	}
	free(int_to_hex);
	return (chars_written);
}

unsigned int	print_pointer(unsigned long int arg)
{
	unsigned int	chars_written;
	char			*ptr_to_hex;

	if (arg == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	chars_written = write(1, "0x", 2);
	ptr_to_hex = ft_ulitohex(arg, HEXALOW);
	chars_written += write(1, ptr_to_hex, ft_strlen(ptr_to_hex));
	free(ptr_to_hex);
	return (chars_written);
}

unsigned int	print_percent_sign(void)
{
	return (write(1, "%", 1));
}
