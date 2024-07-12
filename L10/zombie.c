#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
    pid_t p;
    p = fork();
    if(p>0){
        sleep(100);
    }
        else {
            printf("PID %d",getpid());
        return 0;
        }
    }