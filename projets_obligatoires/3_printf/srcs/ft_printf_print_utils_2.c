/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:20:25 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/11 20:38:40 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Print utilitaries 2 - prints signed/unsigned decimals, and hexadecimals (unsigned).
 * */

#include "ft_printf.h"

unsigned int	print_signed_decimal(int arg)
{
	char	*int_to_alpha;
	int		length;

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

unsigned int	print_unsigned_hex(unsigned int arg, char xcase, t_flags flags)
{
	char			*int_to_hex;
	unsigned int	chars_written;

	chars_written = 0;
	if (flags.hash == 1)
	{
		chars_written += write(1, "0", 1);
		if (arg == 0)
			return (1);
		chars_written += write(1, &xcase, 1);
	}
	if (xcase == 'x')
		int_to_hex = ft_uitohex(arg, HEXALOW);
	else
		int_to_hex = ft_uitohex(arg, HEXAUPP);
	chars_written += write(1, int_to_hex, ft_strlen(int_to_hex));
	free(int_to_hex);
	return (chars_written);
}
