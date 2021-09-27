#include <stdio.h>

int main() {
	int data = 29;
	printf("%x\n", -1);	// just print data
	printf("%x\n", -2);	// just print data
	printf("%x\n", -3);	// just print data
	printf("%x\n", -4);	// just print data
	printf("%x\n", -5);	// just print data
	printf("%x\n", -6);	// just print data
	printf("%x\n", -7);	// just print data
	printf("%x\n", -8);	// just print data
	printf("%x\n", -9);	// just print data
	printf("%x\n", -10);	// just print data
	printf("%x\n", 0);	// just print data
	printf("%x\n", 13);	// just print data
	printf("%x\n", -6565);	// just print data
	printf("%0x\n", data);	// just print data ('0' on its own has no effect)
	printf("%8x\n", data);	// print in 8 width and pad with blank spaces
	printf("%08x\n", data);	// print in 8 width and pad with 0's

	return 0;
}