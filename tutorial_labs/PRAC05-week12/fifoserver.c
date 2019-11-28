#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define FIFONAME "myfifo"


//after termination of the process, it will stay in the system.
int main(int argc, char const *argv[])
{
	int n, fd;
	char buffer[1024];


	//remove any previous FIFO.
	unlink(FIFONAME);

	//create the FIFO.
	if (mkfifo(FIFONAME, 0666) < 0)
	{
		perror("server: mkfifo");
		exit(1);
	}

	//open the FIFO for reading.
	if ((fd  = open(FIFONAME, O_RDONLY)) < 0)
	{
		perror("server: open");
		exit(1);
	}


	//Read from the FIFO until end of file and print 
	//what we get on the standard input.

	while((n = read(fd, buffer, sizeof(buffer))) > 0)
	{
		write(1, buffer, n);
	}

	close(fd);

	exit(0);
}