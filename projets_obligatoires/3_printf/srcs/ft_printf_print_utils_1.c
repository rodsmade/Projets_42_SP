/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:20:21 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/11 21:30:06 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Print utilitaries 1 - prints chars, percent signs, pointers and strings.
 * */

#include "ft_printf.h"

unsigned int	print_char(int arg)
{
	return (write(1, &arg, 1));
}

unsigned int	print_percent_sign(void)
{
	return (write(1, "%", 1));
}

unsigned int	print_pointer(unsigned long int arg)
{
	unsigned int	chars_written;
	char			*ptr_to_hex;

	if (arg == 0)
		return (write(1, "(nil)", 5));
	chars_written = write(1, "0x", 2);
	ptr_to_hex = ft_ulitohex(arg, HEXALOW);
	chars_written += write(1, ptr_to_hex, ft_strlen(ptr_to_hex));
	free(ptr_to_hex);
	return (chars_written);
}

unsigned int	print_string(char *arg)
{
	if (arg == NULL)
		return (write(1, "(null)", 6));
	return (write(1, arg, ft_strlen(arg)));
}
