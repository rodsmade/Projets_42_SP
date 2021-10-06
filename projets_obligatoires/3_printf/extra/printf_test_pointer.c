#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *formatString, ...)
{
	va_list			args_list;
	unsigned long int		pointer;

	va_start(args_list, formatString);
	pointer = va_arg(args_list, unsigned long int);
	char 	*int_to_hex;
	int_to_hex = ft_itoh(pointer, "0123456789abcdef");
	printf("pointer retrieved: 0x%s\n", int_to_hex);
	va_end(args_list);
	return (1);
}

int main() {
	int *intptr;
	int data = 29;
	intptr = &data;
	char *charptr;
	char a = 'a';
	charptr = &a;
	
	// printf("intpointer: %p\n", intptr);	// just print data
	// printf("charpointer: %p\n", charptr);	// just print data

	printf("pointer sent: %p (intptr)\n", intptr);
	ft_printf("lalala", intptr);
	
	printf("pointer sent: %p (charptr)\n", charptr);
	ft_printf("lalala", charptr);

	return 0;
}
