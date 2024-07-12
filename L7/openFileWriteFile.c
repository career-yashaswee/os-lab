#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    int fd1, fd2;
    char buf[50];

    fd1 = open("light", O_CREAT | O_RDWR,0666);
    fd2 = open("rocky", O_CREAT | O_RDWR,0666);
    int n = read(fd1,buf,50);
    write(fd2,buf,n);

}