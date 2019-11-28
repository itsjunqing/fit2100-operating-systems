#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num);
int main() {

	bool primeFound = false;
	int num = 100, primeNumber;

	while (!primeFound) {
		if (isPrime(num)) {
			primeNumber = num;
			primeFound = true;
		}
		num++;
	}
	printf("Prime Number = %d\n", primeNumber);
	return 0;
}

bool isPrime(int num) {
	for (int i = 2; i <= num/2; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}