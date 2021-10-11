/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:20:21 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/11 14:42:00 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		write(1, "0x0", 3);
		return (3);
	}
	chars_written = write(1, "0x", 2);
	ptr_to_hex = ft_ulitohex(arg, HEXALOW);
	chars_written += write(1, ptr_to_hex, ft_strlen(ptr_to_hex));
	free(ptr_to_hex);
	return (chars_written);
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
