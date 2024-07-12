#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include<sys/wait.h>

int main() {
    int fd[2],n;
    char buf[50];
    pid_t p;
    pipe(fd);
    p = fork();
    if(p>0){
        printf("\nParent Passing Value to Children\n");
        write(fd[1],"hello\n",6);
        wait(NULL);
    } else {
        printf("\nI am Child I have Recieved the Value\n");
        n = read(fd[0],buf,50);
        write(1,buf,n);
    }
}