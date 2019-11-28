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


	//open the FIFO for reading. it was created by the server.
	if ((fd  = open(FIFONAME, O_WRONLY)) < 0)
	{
		perror("client: open");
		exit(1);
	}


	//Read from standard input and copy the data to the FIFO.

	while((n = read(0, buffer, sizeof(buffer))) > 0)
	{
		write(fd, buffer, n);
	}

	close(fd);

	exit(0);
}