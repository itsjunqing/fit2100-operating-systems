#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char *first_name;
	char *last_name;
} Name;

bool isSameName(Name a, Name b);

int main() {
	Name a, b;
	a.first_name = "Freedom";
	a.last_name = "Chaos";

	b.first_name = "Freedom";
	b.last_name = "Chaos";

	int result = isSameName(a, b);
	if (result) {
		printf("Name variables are same\n");
	} else {
		printf("Name variables are different\n");
	}
	return 0;
}

bool isSameName(Name a, Name b) {
	if (strcmp(a.first_name, b.first_name) == 0 && strcmp(a.last_name, b.last_name) == 0) {
		return true;
	} 
	return false;
}
