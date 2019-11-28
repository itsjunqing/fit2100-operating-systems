#include <stdio.h>      /* standard I/O routines */
#include <pthread.h>    /* pthread functions and data structures */
#include <unistd.h>     /* we will use sleep() later on in prac */
#include <stdlib.h>     /* needed for exit() function */


/* This function is to be executed by the new thread */
// void* data means storing a memory address rather than integer value
void* print_hello(void* data) {
    long int my_data = (long int) data; /* data received by thread */
        //must cast received data back to original data type.

    pthread_t thread_id = pthread_self();
    pthread_detach(pthread_self());
    printf("Hello from new thread %lu - got %lu\n", (long)thread_id, my_data);

    pthread_exit(NULL);     /* terminate the thread */
}


/* Like any C program, program's execution begins in main */
int main(int argc, char* argv[]) {
    int rc;               /* value returned from thread creation */
    pthread_t thread_id;  /* thread's ID (a long unsigned integer)*/
    long int t = 11;      /* data passed to the new thread */

    pthread_t tid;
    // gets id of the process that is creating the threads
    tid = pthread_self();

    /* create a new thread that will execute 'print_hello()' */
    // rc will be 0 (success) and -1 (failure)
    rc = pthread_create(&thread_id, NULL, print_hello, (void*)tid);

    if(rc) {    /* could not create thread */
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }

    printf("\nI am a thread %lu. Created new thread (%lu) ... \n", (long)tid, (long)thread_id);
    pthread_exit(NULL);     /* terminate the thread */
}
