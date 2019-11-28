#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void count (int start, char ch);

int main (int argc, char *argv[]) {
    int pid;
    int start = 0;

    pid = fork();           /* fork a child process */

    if (pid > 0) {          /* parent continues here */
        count(start, 'P');
        wait(NULL);     
        /* get all printing done before shell prompt shows*/
    } else if (pid == 0) {  /* child got here! */
        system("ps -e -l");
        count(start, 'C');
    } else {                /* only if there was a problem with fork */
        perror("Failed to fork a process");
        exit(1);
    }
}

void count (int start, char ch) {
    int i, j;

    for (i = start; i < 10; i++) {
        // for (j = 0; j < 500000; j++);      /* delay */
        sleep(2);
        printf("Message from %c at the %dth iteration\n", ch, i);
    }
}
