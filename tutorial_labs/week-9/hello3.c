#include <stdio.h>      /* standard I/O routines */
#include <pthread.h>    /* pthread functions and data structures */
#include <unistd.h>
#include <stdlib.h>     /* needed for exit function */


/* This function is to be executed by the new thread */
void* print_hello(void* data) {
    pthread_t tid = (pthread_t) data;  /* data received by thread */
    
    // using this pthread_join kills target thread before executing the current thread (aka waiting for it to die/terminate)
    pthread_join(tid, NULL);        /* wait for thread: tid */
    
    // using this phread_detach will detach itself (aka separate itself) from the parent thread  
    // pthread_detach(pthread_self());

    printf("Hello from new thread %lu - got %lu\n", (long)pthread_self(), (long)tid);
    pthread_exit(NULL);         /* terminate the thread */
}

int main(int argc, char* argv[]) {
    int rc;         /* value returned from thread creation*/
    pthread_t thread_id, parent_id; /* thread IDs */

    parent_id = pthread_self();
    rc = pthread_create(&thread_id, NULL, print_hello, (void*) parent_id);
    
    if(rc) {    /* could not create thread */
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
        
    // sleep(1);
    printf("\n Created new thread (%lu) ... \n", (long)thread_id);
    pthread_exit(NULL);
}
