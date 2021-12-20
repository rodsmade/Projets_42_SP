/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:57:47 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/20 02:06:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

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

// USING PIPE TO SPLIT THE JOB BETWEEN TWO PROCESSES - NEXT STEP IS SPLITTING BETWEEN THREE (1 PAR 2 CHIL)
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

//TODO: exercício 1: rescrever esse trem daquele jeito que faz o double diamond kkkk n sei explica
//TODO: exercício 2: e se fossem 3 processos ???