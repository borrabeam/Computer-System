#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#include "common.h"
#include "common_threads.h"
 
volatile int counter = 0; // shared global variable
 
void *mythread(void *arg)
{
    char *letter = arg;
    int i; // stack (private per thread)
    printf("%s: begin [addr of i: %p]\n", letter, &i);
    counter = counter + 1; // shared: only one
    printf("%s: done\n", letter);
    return NULL;
}
 
void *mythread2(void *arg)
{
    char *letter = arg;
    int i; // stack (private per thread)
    printf("%s: begin [addr of i: %p]\n", letter, &i);
    counter = counter - 1; // shared: only one
    printf("%s: done\n", letter);
    return NULL;
}
 
int main(int argc, char *argv[])
{
 
    pthread_t p1, p2, p3, p4;
    printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int)&counter);
    Pthread_create(&p1, NULL, mythread, "T1");
    Pthread_create(&p2, NULL, mythread, "T2");
    Pthread_create(&p3, NULL, mythread, "T3");
    Pthread_create(&p4, NULL, mythread, "T4");
    // join waits for the threads to finish
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);
    printf("main: done [counter: %d]\n", counter);
    return 0;
}