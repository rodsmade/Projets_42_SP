/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_learning_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:57:47 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/31 01:46:28 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

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
// #define PROCESSES 5

// int main()
// {
// 	int i;
// 	int pipes[PROCESSES][2];

// 	i = -1;
// 	while (++i < PROCESSES)
// 	{
// 		pipe(pipes[i]);
// 		printf("pipe%d: [0]: %d, [1]: %d\n", i, pipes[i][0], pipes[i][1]);
// 	}
// }

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

/*
// LEARNING TO PIPE PROPERLY
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

/* // USING PIPE TO SPLIT THE JOB BETWEEN TWO PROCESSES - NEXT STEP IS SPLITTING BETWEEN THREE (1 PAR 2 CHIL)
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

/*
//TODO: exercício 1: mesmo algoritmo escrito daquele jeito que faz o double diamond kkkk n sei explica
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

/*
//TODO: exercício 2: e se fossem 3 processos ???
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