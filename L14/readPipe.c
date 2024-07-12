#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int res,n;
    char buf[100];
    res = open("fifo1",O_RDONLY);
    n = read(res,buf,100);
    printf("Reader Process %d started\n",getpid());
    printf("Data Received  by %d is: %s\n",getpid(),buf);
}