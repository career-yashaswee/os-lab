#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main(){
    int res,n;
    res = open("fifo1",O_WRONLY);
    write(res,"Message",7);
    printf("Sender Process %d sent the Data\n",getpid());
}