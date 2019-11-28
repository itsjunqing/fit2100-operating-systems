#include <stdio.h>

int gcd(int a, int b);

int main() {
	int a, b, result;
	printf("Enter two integers (separated with a space): ");
	scanf("%d %d", &a, &b);
	if (a > b) {
		result = gcd(a, b);
	} else {
		result = gcd(b, a);
	} 
	printf("Greatest common divisor = %d\n", result);
	return 0;
}

int gcd(int a, int b) {
	int remainder = a % b;
	while (remainder != 0) {
		a = b;
		b = remainder;
		remainder = a % b;
	}
	return b;
}