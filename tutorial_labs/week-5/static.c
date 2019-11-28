#include <stdio.h>


void some_function();
void another_function ();

int main() {
	// value of something changed after the first instance of some_function is called, static variables are only initialized once and can be referred to many times
	// subsequent callings of the same function will refer to the value assigned during the initialization of the variable
	some_function();
	some_function();
	some_function();

	// value of the variable will be reset back to initialization because non-static variables are local variables in which will be deallocated when the function is returned to the caller
	another_function();
	another_function();
	another_function();


	return 0;
}

void some_function () {
	// even if this function is called many times , the first initialisation //of something = 5 is only done the first time the function is called .
	static int something = 5; //only initialised once something++;
	printf("something = %d\n", something);
	something++;
}

void another_function () {
	int something = 5; //only initialised once something++;
	printf("something = %d\n", something);
	something++;
}