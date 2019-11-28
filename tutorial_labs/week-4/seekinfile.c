#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct record {
	int userid;
	char username[6];
};

void readRecordfile() {
	int infile = open("recordfile", O_RDONLY);
	struct record data;

	if (infile < 0) {
		perror("recordfile");
		exit(1);
	}

	int orders[4] = {1, 3, 0, 2};

	for(int i = 0; i < 4; ++i) {
		lseek(infile, *(orders+i) * sizeof(struct record), SEEK_SET);
		read(infile, &data, sizeof(struct record));
		write(1, data.username, strlen(data.username));
		write(1, "\n", 1);
	}

	close(infile);
};

char *usernames[] = {"userA", "userB", "userC", "userD"};

/**
 * Main writes a "recordfile" file (or creates if it does not exist in the directory) 
 * and writes the data of each struct record into each line in recordfile
 */
int main(int argc, char *argv[]) {
	int i, outfile;
	struct record eachrec;

	if ((outfile = open("recordfile", O_WRONLY | O_CREAT)) < 0) {
		perror("recordfile");
		exit(1);
	}

	for (i = 3; i >= 0; i--) {
		eachrec.userid = i;
		strcpy(eachrec.username, usernames[i]);

		lseek(outfile, (long) i * sizeof(struct record), SEEK_SET);
		write(outfile, &eachrec, sizeof(struct record));
	}

	close(outfile);

	readRecordfile();
	exit(0);
}

