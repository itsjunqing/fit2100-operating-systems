#include <stdio.h>

int main()
{
	int hours, minutes;
	printf("Enter time in 24-hours format: ");
	scanf("%d:%d", &hours, &minutes);

	if (hours == 0) {
		// midnight 12 am
		hours += 12;
		printf("%d:%02d AM\n", hours, minutes);
	} else if (hours < 12) {
		// midnight from 1am to 11.59am
		printf("%d:%02d AM\n", hours, minutes);
	} else if (hours == 12) {
		// noon 12pm 
		printf("%d:%02d PM\n", hours, minutes);
	} else if (hours < 24) {
		// noon from 1pm to 11.59pm
		hours -= 12;
		printf("%d:%02d PM\n", hours, minutes);
	} else {
		// midnight 12am
		hours -= 12;
		printf("%d:%02d AM\n", hours, minutes);
	}
	return 0;
}
