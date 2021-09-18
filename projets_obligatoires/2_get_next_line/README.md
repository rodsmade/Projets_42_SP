# get_next_line
This project introduces the concepts of static variables, dynamic memory allocation, file descriptors and macros while solving one symple task: that of using Linux standard function `read()` to scan a file for *single lines* (strings of chars with a single trailing `\n` (new line character))

## Files
* ```get_next_line.c```
	function implementation

* ```get_next_line_utils.c``` 
	auxiliary functions (project requirement)

* ```get_next_line.h``` 
	header file

* ```only_skin``` 
	sample text file (and mindblowing lyrical masterpiece too!) for testing purposes. File size: **6940 bytes**; `\n` count: **251**.

* ```main.c``` 
	printing loop iterating over the file. calls get_next_line to fetch each line, then prints.

## Run the program
On your terminal, make sure to be on the same level as *.c files, then run the command:
```c
gcc get_next_line_utils.c get_next_line.c main.c -D BUFFER_SIZE=42 -o get_next_line
```
Here `BUFFER_SIZE` determines the size of the buffer used to read the file (in other words, how manny chars shall be read at once with every `read()` call).
To run the program, enter the following in the command prompt:
```c
./get_next_line
```

You should expect to see the lyrics to Only Skin by Joanna Newsom printed in your terminal window. How cool is that?!