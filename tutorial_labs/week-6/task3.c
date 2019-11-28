#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid;

	printf("X\n");
	pid = fork();
	printf("Y\n");
	printf("pid = %d\n", (int) pid );
	if (pid > 0) {
		wait(NULL);
	}
	printf("Z\n");

	return 0;
}