#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
    pid_t p;
    p = fork();
    if(p==0){
        sleep(20);
        printf("\nI am Child");
        printf("\nMy PID is %d",getpid());
        printf("\nMy Parent PID is %d",getppid());
    } else if(p>0) {
        printf("\nI am Parent having PID %d",getpid());
        printf("\nMyParent PID %d",getppid());
    } else{
        printf("\nChild Aborted");
    } 
    
}