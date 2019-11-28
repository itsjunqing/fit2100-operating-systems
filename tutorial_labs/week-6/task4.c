#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>

int main() {
	// int pid;
	// printf ("FIT2100\n") ;
	// for (int i=0; i < 2; i++) {
	// 	printf("running fork %d\n", i+1);
	// 	pid = fork () ;
	// }
	// printf("pid = %d\n", pid);
	// printf ("FIT2100\n") ;

	int pid;
	printf("FIT2100\n");
	fork();
	fork();
	printf("FIT2100 LAST\n");
	return 0;
}