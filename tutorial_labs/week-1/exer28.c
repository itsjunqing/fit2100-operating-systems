/* sample.c: display command−line arguments */
#include <stdio.h>
int main(int argc, char *argv[]) 
{
	printf("%s %s\n", argv[1], argv[2]); /* argv[0] is the program name */
	return 0;	
}