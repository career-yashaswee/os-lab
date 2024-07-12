#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *func1();
void *func2();

int main() {
    pthread_t th1;
    pthread_t th2;
    pthread_create(&th1,NULL,*func1,NULL);
    pthread_create(&th2,NULL,*func2,NULL);
    pthread_join(th2,NULL);
    pthread_join(th1,NULL);
    return 0;
}

void *func1(){
    int i;
    for(i=0;i<10;i++){
        printf("\nThread 1 Prints: %d",i);
    }
}

void *func2(){
    int i;
    for(i=10;i<20;i++){
        printf("\nThread 2 Prints: %d",i);
    }
}