#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//it creates 2 process
//parent process to write to pipe
//child process for read 


int main(int argc, char const *argv[])
{
	pid_t pid;	//for the child process
	int pipefd[2]; 	//file descriptor for read and write
	int status;  //child process when it terminates


	//create pipe
	if (pipe(pipefd)<0)
	{
		perror("pipe");
		exit(1);
	}

	//create child process
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}

	//child process executes 'cat'
	// P1 -> pipe -> P2
	if(pid == 0)
	{
		// attach the standard input to the pipe
		dup2(pipefd[0], 0); //read from the pipe. stdin = pipefd[0]
		close(pipefd[1]);

		execl("/bin/cat", "cat", NULL);
		perror("exec");
		_exit(127);
	}

	//the parent process is not reading from the pipe
	close(pipefd[0]);  // to stop data leakage

	//write the mail message to the pipe. file descriptor, buffer, size in bytes
	write(pipefd[1], "Greetings. \n\n", 12);
	write(pipefd[1], "This is your program saying hello. \n", 35);
	write(pipefd[1], "Hope you enjoy this week's prac. \n\n", 34);

	//close the pipe and wait for the child to exit.

	close(pipefd[1]);
	waitpid(pid, &status, 0);


	exit(0);
}
