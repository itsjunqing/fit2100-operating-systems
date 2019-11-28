#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
	srand(time(NULL));
	// first solution
	int sequence[6];
	printf("Random number generated: ");
	for (int i = 0; i < 6; i++)
	{
		sequence[i] = rand() % 10;
		printf("%d", sequence[i]);
	}
	printf("\n");

	// second solution
	// printf("Random number generated: %d\n", rand() % 999999);
	return 0;
}