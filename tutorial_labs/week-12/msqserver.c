#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSQKEY  34858
#define MSQSIZE 32

struct msgbuf {
    long mtype;
    char mtext[MSQSIZE];
};


int main(int argc, char *argv[]) 
{
    key_t key;
    int n, msqid;
    struct msgbuf mbuf;
    
    //Create a new message queue. IPC_CREAT is used to create it.
    //We assume that the key defined in MSQKEY isn't in use by
    //another process.
    key = MSQKEY;
    if ((msqid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("server: msgget");
        exit(1);
    }
    
    /*
     * Receive messages from the queue. 
     * Messages of type 1 are to be printed on the standard output; 
     * a message of type 2 indicates that no more data.
     */
    
    while((n = msgrcv(msqid, &mbuf, MSQSIZE, 0, 0)) > 0) {
        if (mbuf.mtype == 1) {
            /* 
             * YOUR TASK:
             * Write messages of type 1 to the standard output. 
             */
            write(1, mbuf.mtext, n);
        }
        
        else if (mbuf.mtype == 2) {
            //Remove the message queue from the system.
            if (msgctl(msqid, IPC_RMID, (struct msqid_ds *) 0) < 0) {
                perror("server: msgctl");
                exit(1);
            }
        }
    }
    exit(0);
}
