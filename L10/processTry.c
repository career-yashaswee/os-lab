#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
    pid_t p;
    int i;
    
    for(i=0;i<3;i++){
        p = fork();
    }
    if(p==0){
        printf("\nProcess %d PID is:%d\n",i,getpid());
        printf("\nParent of Process %d PID is:%d\n",i,getppid());
    } else {
        wait(0);
    }
    }