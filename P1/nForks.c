#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
void createFork(int n) {
    if(n<=0){
        return;
    }
    pid_t p;
    p = fork();
    if(p==0){
        printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
        createFork(n-1);
        exit(0);
    } else if (p>0){
        wait(NULL);
    } else {
        perror("fork");
        exit(1);
    }
}

int main() {
    int n;
    printf("\nEnter A Value of N\n");
    scanf("%d",&n);
    int value = (int) pow(2,n)-1;
    createFork(value);
    return 0;
}