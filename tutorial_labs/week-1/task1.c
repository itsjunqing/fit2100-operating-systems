#include <stdio.h>

int main() 
{
	char firstName[20];
	char lastName[20];

	printf("Enter first name: ");
	scanf("%s", firstName);

	printf("Enter last name: ");
	scanf("%s", lastName);

	printf("First name's first letter: %c\n", firstName[0]);
	printf("Last name's first letter: %c\n", lastName[0]);
	return 0;
}