#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 9
#define ROW 10
#define COL 10

int main()
{
	printf("Welcome to C programming\n");
	printf("MAX_LENGTH is %d\n", MAX_LENGTH);

	int i=0, j=1, k=2;
	float pi=3.1415926553f;
	double e = 1.0e-32;
	char c = 'a';
	char newline = '\n';

	j = 10;
	printf("value of j = %d%c", j, newline); 

	int a[10];
	a[2] = 3;

	printf("--------- EXERCISE 2.5 --------- \n");
	char unit_code[MAX_LENGTH];
	strcpy(unit_code, "OS");
	printf("unit_code = %s\n", unit_code);

	int matrix[ROW][COL];
	matrix[9][9] = 100;
	printf("matrix[9][9] = %d\n", matrix[9][9]);

	

	printf("--------- EXERCISE 2.6 --------- \n");


	return 0;
}
