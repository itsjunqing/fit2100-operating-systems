#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int n, infile, outfile;
	char buffer[1024];
	char *description = (char *) malloc(sizeof(char) * 100);

	if (argc != 3) {
		write(2, "Usage: ./appendfile file1 file2\n", 32);
		exit(1);
	}

	/*
	* Open the first file ( file1 ) for reading */
	if ((infile = open(argv[1], O_RDONLY)) < 0) { 
		perror(argv[1]);
		exit(1);
	}
	// printf("opened the fd = %d\n", infile);
	write(1, "opened the fd = 3\n", 18);
	
	/*
	* Open the second file ( file2 ) for writing */
	if ((outfile = open(argv[2], O_WRONLY)) < 0) { 
		perror(argv[2]);
		exit(1);
	}
	write(1, "opened the fd = 4\n", 18);
	
	/*
	* CODE HERE: Copy data from the first file to the second file */

	n = read(infile, buffer, 1024); // n is number of bytes read, should be less than 1024 bytes
	if (n < 0) {
		perror("error in reading!\n");
		exit(1);
	}

	// move to the end of file, alternatively, set the outfile as O_APPEND so that only append to the end of file operation is allowed
	lseek(outfile, 0, SEEK_END);	
	n = write(outfile, buffer, n);
	if (n < 0) {
		perror("error in writing!\n");
		exit(1);
	}

	/*
	* Close the two files before exiting */

	close(infile); 
	close(outfile); 
	exit(0);
}