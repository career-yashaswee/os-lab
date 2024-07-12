#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main(){
    FILE *rd;
    char BUF[50];
    sprintf(BUF,"First Name");
    rd = popen("ls","r");
    fread(BUF,1,50,rd);
    printf("%s\n",BUF);
    pclose(rd);
}   