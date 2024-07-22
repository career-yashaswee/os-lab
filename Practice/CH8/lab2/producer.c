#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

#define SHM_SIZE 1024
#define SHM_KEY (key_t) 123

int main() {
    int shmid;
    char* shm;
    shmid = shmget(SHM_KEY,SHM_SIZE,0666 | IPC_CREAT);
    if(shmid==-1){
        printf("shmid");
    }
    printf("")
    shm = shmat(shmid,NULL,0);
    if(shm==(void*)-1){
        printf("shmat");
    }
    for(int i=1;i<=10;i++){

    }
}