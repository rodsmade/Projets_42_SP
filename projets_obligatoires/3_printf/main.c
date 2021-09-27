#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void print_ints(int num, ...);
void print_chars(int num, ...);
void printem(va_list args_list, int num);

int main()
{
	print_ints(5, 'a', 'b', 'c', 'd', 'e');
	// print_chars(5, 65, 66, 67, 80, 77);
	return (0);
}

void print_ints(int num, ...)
{
	va_list args_list;

	va_start(args_list, num);

	printem(args_list, num);

	va_end(args_list);
}

void print_chars(int num, ...)
{
	va_list args_list;

	va_start(args_list, num);

	printem(args_list, num);

	va_end(args_list);
}

void printem(va_list args_list, int num)
// conclusão: tá rolando de fazer function call tanto com a lista
// como com um ponteiro pra lista.
{
	for (int i=0; i < num; i++)
	{
		int value = va_arg(args_list, int);
		// value += 48;
		write(1, &value, 1);
		write(1, "\n", 1);
	}
}