#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main() {  
    printf(“Start\n”);  
    if (fork() == 0) {  
    printf(“One\n”);  
    if (fork() != 0) {  
    printf(“Two\n”);  
    if (fork() != 0) {  
    printf(“Three\n”);  
    }  
    }  
    }  
    printf(“End\n”);  
}  
