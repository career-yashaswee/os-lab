#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int pipe_fd[2];
    char BUFFER[100];
    if(pipe(pipe_fd)<0) {
        printf("ERROR CREATING PIPE");
        return 1;
    }
    pid_t pid = fork();
    if(pid<0){
        printf("FORKING FAILED");
    } else if (pid>0) {
        
        printf("PARENT CODE");
        close(pipe_fd[1]);
        read(pipe_fd[0],BUFFER,sizeof(BUFFER));
        printf("Contents of the File are:%s",BUFFER);
        close(pipe_fd[0]);
    } else {
        printf("CHILD CODE");
         close(pipe_fd[0]);
        char message[] = "I Love You Smita";
        write(pipe_fd[1],message,sizeof(message));
        close(pipe_fd[1]);
    }
    return 0;


}