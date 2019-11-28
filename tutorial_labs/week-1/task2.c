#include <stdio.h>

#define PI 3.1415926553f

int main() 
{
	double radius;
	printf("Enter radius of circle: ");
	scanf("%lf", &radius);

	double circum = 2 * PI * radius;

	printf("Circumference of circle = %.2f\n", circum);
	return 0;
}