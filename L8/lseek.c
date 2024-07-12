#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    char BUF[50];
    int fd;
    fd = open("./location",O_RDONLY);
    read(fd,BUF,10);
    write(1,BUF,10);
    read(fd,BUF,10);
    write(1,BUF,10);
}   