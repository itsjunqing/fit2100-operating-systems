#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCKETNAME "mynewsocket"


int main(int argc, char *argv[])
{
    char buffer[1024];
    int n, sock, nsock, len;
    struct sockaddr_un name;

    //Create a socket.
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        perror("server: socket");
        exit(1);
    }
    

    //Create the address of the server.
    memset(&name, 0, sizeof(struct sockaddr_un));
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, SOCKETNAME);
    len = sizeof(name.sun_family) + strlen(name.sun_path);
    
    //Remove any pervious socket.
    unlink(name.sun_path);
    
    //Bind the socket to the address.
    if (bind(sock, (struct sockaddr*) &name, SUN_LEN(&name)) < 0) {
        perror("server: bind");
        exit(1);
    }
    
    //Listen for connections.
    if (listen(sock, 5) < 0) {
        perror("server: listen");
        exit(1);
    }
    

    //Accept a connection.
    if ((nsock = accept(sock, (struct sockaddr *) &name, &len)) < 0) {
        perror("server: accept");
        exit(1);
    }
    

    /*
     * YOUR TASK:
     * Read from the new socket until end-of-file and
     * print all the data received on the standard output.
     */
    while((n = recv(nsock, buffer, sizeof(buffer), 0)) > 0)
    {
        write(1, buffer, n);
    }

        

    close(nsock);
    close(sock);
    exit(0); 
}
