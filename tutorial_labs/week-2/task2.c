#include <stdio.h>

int main()
{
	char string = 'a';
	printf("Enter a word: ");
	scanf("%s", string);  
	printf("You entered: %c", string);

	return 0;
}