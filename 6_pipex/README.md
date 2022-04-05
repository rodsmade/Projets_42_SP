# pipex
Executing Unix processes in C.

![Pipex - Visualisação do pipe (3)](https://user-images.githubusercontent.com/49699403/149808579-819964fd-6254-4be4-a6d9-a33db200660e.jpg)

Pipex's goal is to replicate the behaviour of the pipe operator (|) in a Bash command line.
To get there, one must learn about the `exec*` function family, forking and waiting on child processes, and file redirection with the `dup*` function family, going as far as managing whitespaces and single/double quotes on the incoming arguments. Such a blast!

Due to the beginner nature of this project (moving forward in the curriculum we have to code our own mini-shell!), when calling the `./pipex` program one must pass the arguments following a specific order:

``` shell
./pipex "input_file" "cmd1 -flags" "cmd2 -flags" ... "cmdN -flags" "output_file"
```

which holds equivalence to the original bash command:

``` shell
< input_file cmd1 -flags | cmd2 -flags | ... | cmdN -flags > output_file
```


