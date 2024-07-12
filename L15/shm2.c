#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
    int i;
    void *shared_memory;
    char buf[100];
    int shmid;
    shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
    //create shared memory segment with key 2345, having size 1024 bytes.
    //IPC_CREAT is used to crate the shared segment if it does not exist.
    //0666 are permissions on the shared segment.
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    //process attached to shared memory
    printf("Process attached at %p\n",shared_memory);
    //this prints address where segment is attached with process
    printf("Enter some data to write to memory\n");
    read(0,buf,100);
    strcpy(shared_memory,buf);
    printf("you wrote:%s\n",(char*)shared_memory);
}