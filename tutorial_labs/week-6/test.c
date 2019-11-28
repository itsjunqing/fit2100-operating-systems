#include <stdio.h>
#include <unistd.h>

int main() {
	int i = getpid();
	printf("hi %d\n", i);

	i = fork();
	printf("%d\n", i);
	return 0;
}