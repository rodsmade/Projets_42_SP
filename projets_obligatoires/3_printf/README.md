# ft_printf
The main goal is to reproduce the behaviour of the beloved _printf_ function in the traditional libc/stdio.h library, while introducing the concepts of _variadic arguments_ in C functions. This was also a great opportunity to learn how to take the most out of the *Make* build automation tool, and how to organise a bigger project using a _directory tree_ to make the project tidier, neater and more understandable.

_You can find more about the making of this project [over here](https://beryl-allium-579.notion.site/Printf-9b57272e356c45968455fe31b47952fc) (in Portuguese 🇧🇷)_

## Scope of project + bonus part
This project is meant to implement the following formats and flags:
``` c
# define FORMATS	"cspdiuxX%"
# define FLAGS		"#0+- ."
```
As I've been pressed for time, this time around the only bonus flag I managed to implement was the # (goes along with x/X formats); However, the groundwork has been laid for the implementation of remaining flags, by means of the **flags** struct implemented in the header file ```ft_printf.h``` and the function **capture_flags()** in ```ft_printf.c```.

## Directories
* ```bin/```
	Where the final executable binary file goes.

* ```headerfiles/``` 
	Keeps all the custom-made .h header files used in the project.

* ```libs/``` 
	Keeps the local custom-made library Libft (see [this project](https://github.com/rodsmade/Projets_42_SP/tree/main/projets_obligatoires/1_libft) for reference), which comprises some of the functions needed for converting integer to strings or int to hexadecimal, for instance.

* ```objs/``` 
	Keeps all the .o files produced throughout the compilation process.

* ```srcs/```
	Where all the good stuff goes!

## Source codes
* ```ft_printf.c```
	Implements the main logic of the function. Reads through the format string (first argument sent in the function, mandatory) byte by byte and decides whether it should be printed as is, or if it should invoke one argument from the variable argument list to convert it into its printable format.

* ```ft_printf_utils_1.c``` and ```ft_printf_utils_2.c``` 
	Auxiliary functions used to handle the arguments, convert them to the corresponding % format, and print the arguments.

## Run the program
On your terminal, make sure to be in the root directory, then run the command:
```c
make
```
You've created the static library ft_printf.a! The next step is to run the command:
```c
make run
```
The file _main.c_ in the root directory can be tweaked however you please in order to see the magic happening! Cooooooool!

### Input
```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("%s!!\n", "Hello world");
	return (0);
}
```

### Output
```shell
Hello world!!

```
