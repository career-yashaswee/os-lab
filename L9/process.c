#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
    pid_t p;
    p = fork();
    if(p==0){
        printf("Child Born\n");
    } else if (p>0) // Parent Code
    {
        wait(0);
        //Wait is used to allow one process to wait for another process to finish the process.
        printf("I am a Parent\n");
    } else {
        printf("Process Not Created\n");
    }
    
}