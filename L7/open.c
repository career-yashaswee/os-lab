#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    int fd;
    char buf[50];

    fd = open("abc.txt", O_CREAT | O_RDWR,0666);
    int n = read(0,buf,50);
    write(1,buf,n);

}