/* 
 *      thread.c
 *      Demonstration of multiple threads
 *
 *      To compile:
 *              gcc  -o thread thread.c -lpthread
 *
 *      To run:
 *              ./thread
 */
          
#include <pthread.h>
#include <stdio.h>

pthread_t tid1, tid2;

/* Function prototypes */
void *pthread1(void *), *arg1;
void *pthread2(void *), *arg2;

/* The main function */
int main() {
	int err;

    /* try to start pthread 1 by calling pthread_create() */
    err = pthread_create(&tid1, NULL, pthread1, arg1);
        
	if (err) {
		printf("\n Error in creating the thread 1: ERROR code %d \n", err);
        return 1;
    }
        
	/* try to start pthread 2 by calling pthread_create() */
    err = pthread_create(&tid2, NULL, pthread2, arg2);
        
	if (err) {
		printf ("\nError in creating the thread 2: ERROR code %d \n", err);
        return 1;
	}

    /* wait for both threads to complete */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
	printf("\n");
}


/* The first thread - it just does a whole lot of counting to take up some CPU time */
void *pthread1(void *param)
{
    float x;
    int i, j;

    printf("\nthread 1 is executing\n");

    for ( i=0; i<50000; i++) {
        for ( j=0; j<10000; j++) {
		    x++;
        }
	}

    /* we don't bother to display the final value of x */
    printf("\nthread 1 now terminating\n");
    pthread_exit(NULL);     /* terminate the thread */
}


/* The second thread - it too just does a whole lot of counting to waste some CPU time */
void *pthread2(void *param)
{
    float y;
    int i,j;

    printf("\nthread 2 has started\n");

    for ( i=0; i<50000; i++) {
        for ( j=0; j<10000; j++) {
            y++;
        }
    }

    /* we don't bother to display the final value of y */
    printf("\nthread 2 now terminating\n");
    pthread_exit(NULL);     /* terminate the thread */
}

