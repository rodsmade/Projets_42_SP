#include <stdio.h>
#include "../headerfiles/ft_printf.h"

void	testeee(char *string, ...)
{
	va_list			args_list;

	va_start(args_list, string);
	va_arg(args_list, char *);
	va_end(args_list);
	printf("%s", string);
}

int main(){
	testeee("NULL %s NULL\n", NULL);
	return (0);
}
