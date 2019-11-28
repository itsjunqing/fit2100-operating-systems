#include <stdio.h>      /* standard I/O routines */
#include <pthread.h>    /* pthread functions and data structures */
#include <unistd.h>
#include <stdlib.h>     /* needed for exit function */

/* This function is to be executed by the new thread */
// void* data means storing a memory address rather than integer value
void* print_hello(void* data) {
    long int my_data = (long int) data; /* data received by thread */
      //must cast received data back to original data type.

    pthread_detach(pthread_self());
    printf("Hello from thread %ld - I was created in iteration %ld\n", my_data, my_data-1);

    pthread_exit(NULL);     /* terminate the thread */
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("append a number at the end of ./hellomany\n");
		return 0;
	}
	int n = atoi(argv[1]);
	
	int rc;               /* value returned from thread creation */
    pthread_t thread_id;  /* thread's ID (a long unsigned integer)*/
    long int t = 11;      /* data passed to the new thread */
	int freq = 0;
    
    for (int i = 1; i <= n; i++) {
        rc = pthread_create(&thread_id, NULL, print_hello, (void*) i);
        freq++;
        
        if (rc) {
        	printf("ERROR: return code from pthread_create is %d\n", rc);
        	exit(1);
        }

        printf("I am thread 1. Created new thread (%d) in iteration %d...\n", i, i-1);

        if (freq == 5) {
        	freq = 0;
        	sleep(1);
        }
    }
    
    pthread_exit(NULL);     /* terminate the thread */

    return 0;
}