#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// NULL is end of argument
	// execl("/bin/ls", "/bin/ls", "-l", NULL);

	char *params[] = {"ls", "-l", 0};
	execv("/bin/ls", params);
	// execvp("/bin/ls", params);
	
	return 0;
}