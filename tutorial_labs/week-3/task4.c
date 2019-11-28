#include <stdio.h>

int *find_smallest(int array[], int n);

int main() {
	int arr[] = {5,4,3,2,1};
	int *address = find_smallest(arr, sizeof(arr) / sizeof(int));
	printf("smallest element = %d\n", *address);
	printf("address of smallest element = %p\n", address);
	return 0;
}

int *find_smallest(int array[], int n) {
	// assuming that array size is not zero
	int *min = &array[0];
	for (int i = 1; i < n; ++i) {
		if (array[i] < *min) {
			min = &array[i];
		}
	}
	return min;
}
