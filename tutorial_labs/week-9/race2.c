/* 
 *      race.c - demonstrate a Race Condition
 *
 *      To compile:
 *              gcc -o race race.c -lpthread
 *
 *      To run:
 *              ./race
 */
  
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid1, tid2;
pthread_mutex_t locker;

/* Function prototypes */
void *pthread1(void *), *arg1;
void *pthread2(void *), *arg2;

/* This is the global variable shared by both threads, initialised to 50.
 * Both threads will try to update its value simultaneously.
 */
int theValue = 50;

/* The main function */
int main()
{
    int err;

    /* initialise the random number generator to sleep for random time */
    srand (getpid());

    /* try to start pthread 1 by calling pthread_create() */
    err = pthread_create(&tid1, NULL, pthread1, arg1);

    /* initialise locker for pthread_mutex_t */
    if (pthread_mutex_init(&locker, NULL) != 0) {
        printf("\n mutex init failed\n");
        return 1;
    }
        
    if(err) {
        printf ("\nError in creating the thread 1: ERROR code %d \n", err);
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

    /* display the final value of variable theValue */
    printf ("\nThe final value of theValue is %d \n\n", theValue);
}


/* The first thread - it increments the global variable theValue */
void *pthread1(void *param)
{
    int x;
    printf("\nthread 1 has started\n");

    /*** The critical section of thread 1 */
    pthread_mutex_lock(&locker);
    sleep(rand() & 1);      /* encourage race condition */
    x = theValue;
    sleep(rand() & 1);      /* encourage race condition */
    x++;                    /* increment the value of theValue by 1 */
    sleep(rand() & 1);      /* encourage race condition */
    theValue = x;
    /*** The end of the critical section of thread 1 */
    pthread_mutex_unlock(&locker);

    printf("\nthread 1 now terminating\n");
    pthread_exit(NULL);     /* terminate the thread */
}


/* The second thread - it decrements the global variable theValue */
void *pthread2(void *param)
{
    int y;
    printf("\nthread 2 has started\n");

    /*** The critical section of thread 2 */
    pthread_mutex_lock(&locker);
    sleep(rand() & 1);      /* encourage race condition */
    y = theValue;
    sleep(rand() & 1);      /* encourage race condition */
    y--;                    /* decrement the value of theValue by 1 */
    sleep(rand() & 1);      /* encourage race condition */
    theValue = y;
    /*** The end of the critical section of thread 2 */
    pthread_mutex_unlock(&locker);

    printf("\nthread 2 now terminating\n");
    pthread_exit(NULL);     /* terminate the thread */
}

