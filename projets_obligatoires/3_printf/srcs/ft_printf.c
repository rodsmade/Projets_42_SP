/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:56 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/08 17:23:19 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

flags	all_flags;

unsigned int	convert_format(const char *formatStr, va_list args_list);
int				capture_flags(const char *formatStr);
void			initialise_flags(void);

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
