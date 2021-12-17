// fork tests
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


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
	if (child_pid > 0)
	{
		printf("This is the parent process whereupon a fork returns a positive pid which is it's child's pid\n");
		printf("parent_pid: %d\n", parent_pid);
		printf("child_pid: %d\n", child_pid);
		printf("getpid(): %d\n", getpid());
	}
	if (child_pid == 0)
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


/*
int main()
{
	printf("I am: %d\n", (int) getpid());

	pid_t pid = fork();
	printf("fork returned: %d\n", (int) pid);

	printf("I am: %d\n", (int) getpid());

	return (0);
}
*/