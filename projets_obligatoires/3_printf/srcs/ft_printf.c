/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:55:56 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/06 11:58:07 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

unsigned int	convert_format(const char *formatStr, va_list args_list);
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
		return (print_signed_decimal(va_arg(args_list, int)));
	if (*formatStr == 'u')
		return (print_unsigned_decimal(va_arg(args_list, unsigned int)));
	if (*formatStr == 'c')
		return (print_char(va_arg(args_list, int)));
	if (*formatStr == 's')
		return (print_string(va_arg(args_list, char *)));
	if (*formatStr == 'x' || *formatStr == 'X')
		return (print_unsigned_hex(va_arg(args_list, unsigned int), *formatStr));
	if (*formatStr == 'p')
		return (print_pointer(va_arg(args_list, unsigned long int)));
	if (*formatStr == '%')
		return (print_percent_sign());
	return (0);
}

unsigned int	print_signed_decimal(int arg)
{
	char	*int_to_alpha;
	// ao invés de guardar em um int, guarda em um struct 

	int_to_alpha = ft_itoa(arg);
	ft_putstr_fd(int_to_alpha, 1);
	return (ft_strlen(int_to_alpha));
}

unsigned int	print_unsigned_decimal(unsigned int arg)
{
	char	*int_to_alpha;

	int_to_alpha = ft_itoa(arg);
	ft_putstr_fd(int_to_alpha, 1);
	return (ft_strlen(int_to_alpha));
}

unsigned int	print_char(int arg)
{
	return (write(1, &arg, 1));
}

unsigned int	print_string(char *arg)
{
	unsigned int	chars_written;

	chars_written = 0;
	while (*arg)
	{
		chars_written += write(1, arg, 1);
		arg++;
	}
	return (chars_written);
}

unsigned int	print_unsigned_hex(unsigned int arg, char xcase)
{
	char			*int_to_hex;
	unsigned int	chars_written;

	chars_written = 0;
	if (xcase == 'x')
		int_to_hex = ft_uitohex(arg, HEXALOW);
	else
		int_to_hex = ft_uitohex(arg, HEXAUPP);
	while (*int_to_hex)
	{
		chars_written += write(1, int_to_hex, 1);
		int_to_hex++;
	}
	return (chars_written);
}

unsigned int	print_pointer(unsigned long int arg)
{
	unsigned int	chars_written;
	char			*ptr_to_hex;

	chars_written = write(1, "0x", 2);
	// TODO: essa conv vai dar ruim pq itohex converte só uint!!!
	ptr_to_hex = ft_ulitohex(arg, HEXALOW);
	chars_written = write(1, ptr_to_hex, ft_strlen(ptr_to_hex));
	return (chars_written);
}

unsigned int	print_percent_sign(void)
{
	return (write(1, "%", 1));
}


#include <stdio.h>
int main()
{
	char	*ptr;
	char	aaa = '*';
	ptr = &aaa;

	ft_printf("------------------------------------------------------\nQue comecem os testes:\n");
	ft_printf("i: %i\t\t\t--\tinput: 42\n", 42);
	ft_printf("d: %d\t\t\t--\tinput: 42\n", 42);
	ft_printf("u: %u\t\t\t--\tinput: -42\n", -42);
	ft_printf("c: %c\t\t\t--\tinput: 42\n", 42);
	ft_printf("s: %s\t--\tinput: Quarenta e dois\n", "Quarenta e dois");
	ft_printf("x: %x\t\t\t--\tinput: 42\n", 42);
	ft_printf("X: %X\t\t\t--\tinput: 42\n", 42);
	ft_printf("p: %p\t--\tinput: um ponteiro sla\n", ptr);
	ft_printf("percent: %%\t\t--\tinput: void\n");
	return (0);
}
