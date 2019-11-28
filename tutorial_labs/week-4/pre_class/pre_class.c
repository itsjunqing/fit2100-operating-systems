#include <stdio.h>
#include "arithmetic.h"

int main(void)
{
	int a, b;
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);

	printf("Addition value = %d\n", addition(a, b));
	printf("Subtraction value = %d\n", subtraction(a, b));
	printf("Multiplication value = %d\n", multiplication(a, b));
	printf("Division value = %d\n", division(a, b));
	return 0;
}
	

