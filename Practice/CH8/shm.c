#include<string.h>
#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>


#define SHM_SIZE 1024
int main() {
    int shmid;
    char *shm;
    shmid = shmget((key_t)123,SHM_SIZE,0666|IPC_CREAT);
    if(shmid==-1){
        printf("error");
        perror("shmget");
    }
    printf("Key value of shared memory is: %d\n",shmid);
    shm=shmat(shmid,NULL,0);
    if(shm == (void*)-1){
        perror("shm");
    }
    printf("Process attached to the address of: %p\n",shm);
    char BUFF[100];
    fgets(BUFF,sizeof(BUFF),stdin);
    BUFF[strcspn(BUFF,"\n")]='\0';
    strncpy((char*)shm,BUFF,SHM_SIZE);
    printf("Here is the message from SHM:%s",(char*)shm);

}