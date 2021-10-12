# ft_printf
	The main goal is to reproduce the behaviour of the beloved _printf_ function in the traditional stdio.h (LibC) library, while introducing the concepts of _variadic arguments_ in C functions. This was also a great opportunity to learn how to take the most out of the *Make* build automation tool, and how to organise a bigger project using a _directory tree_ to make the project tidier, neater and more understandable.

## Scope of project + bonus part
	As I've been pressed for time, 

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

* ```ft_printf_utils_1.c and ft_printf_utils_2.c``` 
	auxiliary functions used to handle the arguments, convert them to the corresponding % format, and print the arguments.

## Run the program (TO DO)
On your terminal, make sure to be on the same level as the *.c files, then run the command:
```c
make
```
You've created the static library ft_printf.a! The next step is to run the command:
```c
make run
```
In order for this to work, you'll need the _main.c_ file calling ft_printf(). You can tweak this file however you want to see the magic happening! Cooooooool!