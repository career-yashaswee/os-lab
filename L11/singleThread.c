#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *func1();
char message[] = "hello";
int main() {
    pthread_t th;
    printf("Inside a Main Function");
    pthread_create(&th,NULL,*func1,message);
    pthread_join(th,NULL);
    return 0;
}

void *func1(void *arg){
    printf("\nFunc1 Returned %s\n",arg);
}