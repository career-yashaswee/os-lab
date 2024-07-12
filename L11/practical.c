#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *mult(){
    int num = 8;
    for(int i=1;i<=10;i++){
        printf("\n%d X %d = %d\n",num,i,num*(i));
    }
        return NULL;
}    

int main() {
    pid_t p;
    pthread_t th;
    p = fork();
    if(p==0){
        printf("\nI am a Child Process with PID:%d\n",getpid());
        printf("\nMy Parent PID:%d\n",getppid());
        return 0;
    } else if (p>0){
        printf("\nI am a Parent with PID:%d\n",getpid());
        printf("\nMy Parent PID:%d\n",getppid());
    } else {
        printf("Error Forking Child Process");
    }
    pthread_create(&th,NULL,*mult,NULL);
    pthread_join(th,NULL);
    return 0;
}