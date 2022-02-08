/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_learning_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:57:47 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/09 10:27:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

/*
int main()
{
	int pipe1[2];
	pipe(pipe1);
	printf("pipe1: [0]: %d, [1]: %d\n", pipe1[0], pipe1[1]);
	int pipe2[2];
	pipe(pipe2);
	printf("pipe1: [0]: %d, [1]: %d\n", pipe2[0], pipe2[1]);
	int pipe3[3];
	pipe(pipe3);
	printf("pipe1: [0]: %d, [1]: %d\n", pipe3[0], pipe3[1]);
	return (0);
}
*/

// entendendo como pipes são criados (mais de um no msm pgm)
/*#define PROCESSES 5

int main()
{
	int i;
	int pipes[PROCESSES][2];

	i = -1;
	while (++i < PROCESSES)
	{
		pipe(pipes[i]);
		printf("pipe%d: [0]: %d, [1]: %d\n", i, pipes[i][0], pipes[i][1]);
	}
}
*/

/*
// entendendo como o access() funciona e se ele funciona pra identificar se um comando existe
// sei que /usr/local/bin/norminette existe. 
int main()
{
	printf("access return: %i\n", access("/sr/local/bin/norminette", F_OK));
	return 0;
}
*/

/*
int main()
{
	pid_t parent_pid;
	pid_t child_pid;

	parent_pid = getpid();
	printf("parent process pid no cast: %d\n", parent_pid);
	printf("this is right before fork\n");
	child_pid = fork();
	if (child_pid < 0)
		perror("Fork failed\n");
	else if (child_pid > 0)
	{
		printf("This is the parent process whereupon a fork returns a positive pid which is it's child's pid\n");
		printf("parent_pid: %d\n", parent_pid);
		printf("child_pid: %d\n", child_pid);
		printf("getpid(): %d\n", getpid());
	}
	else
	{
		printf("it means i forked inside a child process, whereupon a fork returns 0\n");
		printf("parent_pid: %d\n", parent_pid);
		printf("child_pid: %d\n", child_pid);
		printf("getpid(): %d\n", getpid());
		exit(0);
	}
	// printf("this is right after ifs\n");
	// printf("parent_pid: %d\n", parent_pid);
	// printf("child_pid: %d\n", child_pid);
	// printf("getpid(): %d\n", getpid());
	printf("end of program, right before return\n");
	return 0;
}
*/

// LEARNING TO PIPE PROPERLY
/*
int main()
{
	int		pipefd[2];
	int		transfer;
	pid_t	pid;

	// from manual: pipefd[0] refers to the read end of the pipe.
	// pipefd[1] refers to the write  end  of  the  pipe.
	if (pipe(pipefd) == -1)
	{
		printf("An error ocurred while piping a a a\n");
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("An error ocurred while forking :O\n");
		return (0);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		transfer = -42000;
		write(pipefd[1], &transfer, sizeof(int));
		close(pipefd[1]);
		return (0);
	}
	else
	{
		close(pipefd[1]);
		int	buffer;
		wait(NULL);
		read(pipefd[0], &buffer, sizeof(int));
		printf("number read from pipefd: %d\n", buffer);
	}
	return (0);
}
*/

// USING PIPE TO SPLIT THE JOB BETWEEN TWO PROCESSES - NEXT STEP IS SPLITTING BETWEEN THREE (1 PAR 2 CHIL)
/*
int main()
{
	int		myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		pipefd[2];
	int		i;
	int		sum;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-2);
	else if (pid == 0)
	{
		close(pipefd[0]);
		//adds up first half of array
		sum = 0;
		i = -1;
		while (++i < 5)
			sum += myArray[i];
		printf("Partial sum: %d\n", sum);
		// puts in pipe
		write(pipefd[1], &sum, sizeof(int));
		close(pipefd[1]);
		return (0);
	}	
	else
	{
		close(pipefd[1]);
		// gets first half sum from pipe
		wait(NULL);
		read(pipefd[0], &sum, sizeof(int));
		printf("Sum from child: %d\n", sum);
		//adds up second half of array
		i = 4;
		while (++i < 10)
			sum += myArray[i];
		printf("Total sum: %d\n", sum);
		close(pipefd[0]);
	}

	return 0;
}
*/

//TODO: exercício 1: mesmo algoritmo escrito daquele jeito que faz o double diamond kkkk n sei explica
/*
int	main()
{
	int		sum;
	pid_t	pid;
	int		pipefd[2];
	int		myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		start, end;

	if (pipe(pipefd) == -1)
		return (-1);
	sum = 0;
	pid = fork();
	if (pid == -1)
		return (-2);
	if (pid == 0) {
		start = -1;
		end = 5;
	} else {
		start = 4;
		end = 10;
	}
	while (++start < end)
		sum += myArray[start];
	printf("Partial sum: %d\n", sum);
	if (pid == 0) {
		close(pipefd[0]);
		write(pipefd[1], &sum, sizeof(int));
		close(pipefd[1]);
	} else {
		wait(NULL);
		close(pipefd[1]);
		read(pipefd[0], &start, sizeof(int));
		close(pipefd[0]);
		sum += start;
		printf("Total sum: %d\n", sum);
	}
	return 0;
}
*/

//TODO: exercício 2: e se fossem 3 processos ???
/*
int main()
{
	int		my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	pid_t	pid;
	int		pipefd[2];
	int		start, end, sum;

	if (pipe(pipefd) == -1)
		return (-1);
	sum = 0;
	pid = fork();
	if (pid == 0)
	{
		start = 4;
		end = 10;
		printf("1st child; pid = %d, ppid = %d\n", getpid(), getppid());
	} else {
		pid = fork();
		if (pid == 0)
		{
			start = 9;
			end = 15;
			printf("2nd child; pid = %d, ppid = %d\n", getpid(), getppid());
		} else {
			start = -1;
			end = 5;
			printf("Parent; pid = %d, ppid = %d\n", getpid(), getppid());
		}
	}
	while (++start < end)
		sum += my_array[start];
	printf("PID %d partial sum: %d\n", getpid(), sum);
	// pipefd[0] => read;
	// pipefd[1] => write;
	if (pid == 0)
	{
		close(pipefd[0]);
		write(pipefd[1], &sum, sizeof(sum));
		close(pipefd[0]);
		return (0);
	}
	if (pid != 0){
		int wait_result = 0;
		while (wait_result != -1)
		{
			if ((wait_result = wait(NULL)) != -1)
			{
				printf("Child %d terminated\n", wait_result);
				close(pipefd[1]);
				read(pipefd[0], &start, sizeof(sum));
				printf("recuperou do pipe: %d\n", start);
				close(pipefd[0]);
				sum += start;
			}
		}
		printf("Total sum: %d\n", sum);
		// ñ deu bom aff ):
	}
	return 0;
}
*/

// CRIANDO N CHILD PROCESSES
#define PROCESS_NO 10

void	do_as_a_child_must(int *pipefd)
{
	int my_value;

	my_value = getpid() % PROCESS_NO;
	printf("I'm a child, pid: %d, ppid: %d\n  my_value: %d\n  pipefd[0]: %d pipefd[1]: %d\n", getpid(), getppid(), my_value, pipefd[0], pipefd[1]);
	close(pipefd[0]);
	write(pipefd[1], &my_value, sizeof(int));
	close(pipefd[1]);
	return ;
}

void	do_as_a_parent_must(int pipefd[PROCESS_NO][2])
{
	int	i;
	int	value_read;

	printf("I am the sole parent, my pid is %d\n", getpid());
	i = -1;
	while (++i < PROCESS_NO)
	{
		close(pipefd[i][1]);
		read(pipefd[i][0], &value_read, sizeof(int));
		close(pipefd[i][0]);
		printf("Value read in iteration %d: %d\n", i, value_read);
	}
	return ;
}

int main()
{
	int i;
	int pids;
	int	pipefd[PROCESS_NO][2];

	i = -1;
	while (++i < PROCESS_NO)
	{
		if (pipe(pipefd[i]) == -1)
			return (-1);
		printf("pipefd[%d]: [0]: %d, [1]: %d\n", i, pipefd[i][0], pipefd[i][1]);
		pids = fork();
		if (pids == -1)
			return (-1);
		if (pids == 0)
		{
			do_as_a_child_must(pipefd[i]);
			return (0) ;
		}
	}
	i = -1;
	while (++i < PROCESS_NO)
		wait(NULL);
	do_as_a_parent_must(pipefd);
	return (0);
}


// RODANDO SHELL CMDS IN C
/**
 * OBSERVAÇÕES:
 * o primeiro arg de execve tem que ser o PATH INTEIRO pro cmd
 * o segundo arg de execve tem que TERMINAR EM NULL
 * 		e por convenção, o primeiro item da lista é o nome do cmd
 * 
 */
/*
int main(int argc, char *argv[], char *envp[])
{
	char	*cmd[] = {"/usr/bin/ls", "ls", "-l", NULL};

	if (execve(cmd[0], cmd + 1, envp) == -1)
		printf("deu ruim\n");
	printf("ahajfhkajhd\n");
	return 0;
}
*/

// RODANDO SHELL CMDS IN C E DEPOIS VOLTANDO PRA MAIN (fork)
/*
int main(int argc, char *argv[], char *envp[])
{
	int 	pid;
	char	*cmd[] = {"/usr/bin/ls", "ls", "-l", NULL};


	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd + 1, envp) == -1)
			printf("deu ruim\n");
		return (0);
	}
	wait(NULL);
	printf("deu bom\n");
}
*/

// RODANDO O COMANDO SHELL EM C E REDIRECIONANDO O OUTPUT PRA UM ARQUIVO

// from man dup2: "after a successful return, the old and new file descriptors
// may be used interchangeably"
// então o fd1 é o arquivo stdout que é o arquivo que aparece no terminal.
// quando faço dup2(meufd, STDOUT), eu fecho o arquivo que aparece no terminal,
// e redireciono tudo o que as funções mandarem para esse fd (1) para o novo fd
// e por isso ambos são usados interchangeably, sendo redirecionados para o
// arquivo novo que eu criei.
// a função printf, e tds os comandos shell, printam seu resultado no fd 1 por
// padrão. só que quando eu faço dup2(novofd, STDOUT), tudo o que for direciona-
// do pra fd1 será redirecionado automaticamente para o novofd.
// also: "If  the file descriptor newfd was previously open,  
// it  is silently closed before being reused." >> é o caso de STDOUT.
// com o novo fd.
// então o "arquivo" STDOUT fecha, e o fd 1 passa a apontar para o novo arquivo
/*
int main(int argc, char *argv[], char *envp[])
{
	int output;
	char	*cmd1[] = {"/usr/bin/ls", "ls", NULL};
	// char	*cmd2[] = {"/usr/bin/grep", "grep", "\"grep\"", NULL};
	char	*cmd3[] = {"/usr/bin/wc", "wc", "-l", NULL};
	int	pid;

	output = open("output.txt", O_WRONLY | O_CREAT, 0777);
	printf("output fd: %i\n", output);
	dup2(output, 1);
	printf("esse texto n vai ser printado no terminal, "
	"mas sim dentro de output.txt, que é o arquivo que corresponde ao novo fd, "
	"para o qual o fd STDOUT (1) foi redirecionado com a função dup2.\n");
	close(output);
	pid = fork();
	if (pid == 0)
		execve(cmd1[0], cmd1 + 1, envp);
	dup2(1, 0);
	execve(cmd3[0], cmd3 + 1, envp);
}
*/

// TENTAR USAR DUP PRA MUDAR O FD 0 (STDIN) PRA UM ARQUIVO DE INPUT
/*
int main(int argc, char *argv[], char *envp[])
{
	char	*cmd3[] = {"/usr/bin/wc", "wc", "-l", NULL};
	int inputfd;

	inputfd = open("input.txt", O_RDONLY);
	dup2(inputfd, STDIN_FILENO);
	execve(cmd3[0], cmd3 + 1, envp);
	// YES PORRA.
}
*/

// USAR PIPE PRA RODAR DOIS COMANDOS EM SEGUIDA
/*
int main(int argc, char *argv[], char *envp[])
{
	char	*cmd_ls[] = {"/usr/bin/ls", "ls", "-l", NULL};
	char	*cmd_wc[] = {"/usr/bin/wc", "wc", "-l", NULL};
	int		pipe_fds[2];
	int		pid;

	int inputfd = open("input.txt", O_RDONLY);
	int outputfd = open("output.txt", O_WRONLY | O_CREAT, 0777);
	pipe(pipe_fds);
	printf("pipe criado: [%i, %i]\n", pipe_fds[0], pipe_fds[1]);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fds[0]);
		dup2(inputfd, STDIN_FILENO);
		dup2(pipe_fds[1], STDOUT_FILENO);
		execve(cmd_ls[0], cmd_ls + 1, envp);
		close(pipe_fds[1]);
	}
	else
	{
		char buff[1000];
		wait(NULL);
		close(pipe_fds[1]);
		dup2(pipe_fds[0], STDIN_FILENO);
		dup2(outputfd, STDOUT_FILENO);
		execve(cmd_wc[0], cmd_wc + 1, envp);
		close(pipe_fds[0]);
	}
	return (0);
}
*/

int main()
{
	int i;
	int pids;
	int	pipefd[PROCESS_NO][2];

	i = -1;
	while (++i < PROCESS_NO)
	{
		if (pipe(pipefd[i]) == -1)
			return (-1);
		printf("pipefd[%d]: [0]: %d, [1]: %d\n", i, pipefd[i][0], pipefd[i][1]);
		pids = fork();
		if (pids == -1)
			return (-1);
		if (pids == 0)
		{
			do_as_a_child_must(pipefd[i]);
			return (0) ;
		}
	}
	i = -1;
	while (++i < PROCESS_NO)
		wait(NULL);
	do_as_a_parent_must(pipefd);
	return (0);
}
int main(int argc, char *argv[], char *envp[])
{
	char	*cmd_ls[] = {"/usr/bin/ls", "ls", "-l", NULL};
	char	*cmd_wc[] = {"/usr/bin/wc", "wc", "-l", NULL};
	int		pipefd[pipe_count][2];
	int		pid;
	int		i;

	int inputfd = open("input.txt", O_RDONLY);
	int outputfd = open("output.txt", O_WRONLY | O_CREAT, 0777);
	i = -1;
	while (++i < process_count)
	{
		if (pipe(pipefd[i]) == -1)
			return (-1);
		printf("pipefd[%d]: [0]: %d, [1]: %d\n", i, pipefd[i][0], pipefd[i][1]);
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			close(pipefd[i][0]);
			dup2(pipefd[i - 1][0], STDIN_FILENO);
			dup2(pipefd[i][1], STDOUT_FILENO);
			execve(cmd[i][0], cmd[i] + 1, envp);
			close(pipefd[i][1]); // n chega aqui, será q dá leak?
		}
	}
	i = -1;
	while (++i < process_count)
		wait(NULL);
	dup2(pipefd[pipe_count - 1], STDIN_FILENO);
	dup2(outputfd, STDOUT_FILENO);
	return (0);
}