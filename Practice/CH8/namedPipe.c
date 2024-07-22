#include<unistd.h>
#include<stdio.h>
#include <sys/stat.h>
#include<fcntl.h>
int main() {
    char *fifo = "./named";
    mkfifo(fifo,0666);
    int fd;
    fd = open(fifo,O_WRONLY);
    write(fd,"I LOVE YOU PIKASAURAS",sizeof("I LOVE YOU PIKASAURAS"));
    close(fd);
    fd = open(fifo,O_RDONLY);
    char BUFF[100];
    read(fd,BUFF,sizeof(BUFF));
    printf("The Data is %s",BUFF);
    close(fd);
    return 0;
}