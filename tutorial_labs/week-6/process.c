#include <unistd.h> 
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() { 
	pid_t pid ;
	char *params[] = {"/bin/ls", "-l", 0};
	
	// pid will be the id of the child process, which is more than 0
	// fork will create a copy of the parent process and determine which process to run first (whether is parent process of child process), depends on the scheduling table - round robin, shortest first, etc
	pid = fork();  // returns the parent id
	printf("pid = %d\n", pid);
	if (pid < 0) 
	{
		perror("fork error");
		exit(1);
	}
	// if pid == 0, currently is running child process
	// if pid > 0, currently is running parent process
	else if (pid == 0)
	{
		printf("running child process\n");
		execv("/bin/ls", params);
	} 
	
	// running the parent process as pid > 0
	else 
	{
		printf("running parent process\n");
		// sleep is used to allow the child process to run first, parent will sleep for 5 seconds while allowing the child process to continue running
		// sleep(5);
		
		// instead of using sleep(5), we may be unsure that child process to complete within 5 seconds, we can use wait() command to wait for child process to continue 
		// wait(0);
		int status;
		// 0 represents NULL
		waitpid(pid, &status, 0);
		printf("parent process completed\n");
	}

	exit(0);
}