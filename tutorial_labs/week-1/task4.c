#include <stdio.h>

int main(void) 
{
	int num, reversed = 0;
	printf("Enter number: ");
	scanf("%d", &num);

	// first solution
	// while (num != 0) 
	// {
	// 	reversed *= 10;
	// 	reversed += num % 10;
	// 	num /= 10;
	// }
	// printf("Reversed number: %d\n", reversed);
	
	// second solution
	int reversedNum[3], index = 0;
	while (num != 0) 
	{
		reversedNum[index] = num % 10;
		num /= 10;
		index++;
	}

	printf("Reversed number: ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d", reversedNum[i]);
	}
	printf("\n");
	return 0;
}