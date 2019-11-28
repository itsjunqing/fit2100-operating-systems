#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIFONAME "myfifo"

int main(int argc, char *argv[])
{
    int n, fd;
    char buffer[1024];

    // Open the FIFO for writing. It was created by the server.
    if ((fd = open(FIFONAME, O_WRONLY)) < 0) {
        perror("client: open");
        exit(1);
    }

    /*
     * YOUR TASK:
     * Read from the standard input, and copy the data to the FIFO.
     */
    
    close(fd);
    exit(0);
}
