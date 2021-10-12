/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:56 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/11 21:48:11 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			initialise_flags(t_flags *flags);
static unsigned int	convert_format(const char *formatStr, va_list args, t_flags flags);
static int			capture_flags(const char *formatStr, t_flags *flags);

int	ft_printf(const char *formatString, ...)
/**
 * This is the variadic function that simulates the behaviour of original libC's printf.
 * Basically it needs to initialise a variable argument list (va_list), and then
 * based off the format string (1st argument), the function should determine 
 * what type must be used to retrieve the next argument in the list, which in turn
 * is converted into a printable output and printed on the terminal.
 * */
{
	unsigned int	write_count;
	va_list			args;
	int				offset;
	t_flags			flags;

	va_start(args, formatString);
	write_count = 0;
	while (*formatString)
	{
		if (*formatString != '%')
			write_count += write(1, formatString, 1);
		else
		{
			if (*(formatString + 1) == '\0')
			// original printf's behaviour in Linux (not MacOS)
				return (-1);
			initialise_flags(&flags);
			formatString++;
			offset = capture_flags(formatString, &flags);
			formatString += offset;
			write_count += convert_format(formatString, args, flags);
		}
		formatString++;
	}
	va_end(args);
	return (write_count);
}

void	initialise_flags(t_flags *flags)
/**
 * This function initialises the struct that keeps tracks of flags being passed on.
 * Because it is impossible to determine which flags will be passed on in the format string
 * from start, the t_flag struct is used to signal which flags are present
 * and must be implemented along with the corresponding argument (in boolean logic, 0 for
 * not present and 1 for present).
 * */
{
	(*flags).blank = 0;
	(*flags).dash = 0;
	(*flags).field_width = 0;
	(*flags).hash = 0;
	(*flags).plus = 0;
	(*flags).precision = 0;
	(*flags).zero = 0;
	return ;
}

unsigned int	convert_format(	const char *formatStr, va_list args, t_flags flags)
/**
 * This function acts as a router to direct the next argument in the list
 * towards the function that will convert and print it on the terminal.
 * If no recognisable format character follows, nothing is printed.
 * */
{
	int	offset;

	offset = capture_flags(formatStr, &flags);
	if (formatStr[offset] == 'i' || formatStr[offset] == 'd')
		return (print_signed_decimal(va_arg(args, int)));
	if (formatStr[offset] == 'u')
		return (print_unsigned_decimal(va_arg(args, unsigned int)));
	if (formatStr[offset] == 'c')
		return (print_char(va_arg(args, int)));
	if (formatStr[offset] == 's')
		return (print_string(va_arg(args, char *)));
	if (formatStr[offset] == 'x' || formatStr[offset] == 'X')
		return (print_unsigned_hex(va_arg(args, unsigned int), formatStr[offset], flags));
	if (formatStr[offset] == 'p')
		return (print_pointer(va_arg(args, unsigned long int)));
	if (formatStr[offset] == '%')
		return (print_percent_sign());
	return (offset);
}

int	capture_flags(const char *formatStr, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_strchr(FLAGS, formatStr[i]))
	{
		if (formatStr[i] == '#')
			(*flags).hash = 1;
		i++;
	}
	return (i);
}
