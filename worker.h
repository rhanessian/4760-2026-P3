#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <time.h>



#define MAXPROC 20
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXTEXT 200
#define PERMS 0644

struct PCB{
	bool occupied;
	int launched;        
    pid_t pid;  
    bool active;          
    int startS;
    int startN;
    int termS;
    int termN;
    int msgsSent;
};

struct sharedMem{
	long long seconds;
	long long nanoseconds;
	struct PCB table[MAXPROC];
};

struct msgbufWorker {
    long mtype;
    int status;
    int intData;
};

struct msgbufOSS {
	long mtype;
	char message[50];
	int intData;
};