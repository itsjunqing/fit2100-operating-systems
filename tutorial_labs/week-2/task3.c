#include <stdio.h>

int main()
{
	char string[50];
	printf("Enter a word: ");
	scanf("%s", string); 
	printf("You entered: \"%s\"\n", string);

	return 0;
}