#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

sem_t s;
int shared = 1;
void *func1();
void *func2();

int main() {
    pthread_t th1;
    pthread_t th2;
    sem_init(&s,0,1);
    printf("\nInside a Main Function\n");
    pthread_create(&th1,NULL,*func1,NULL);
    pthread_create(&th2,NULL,*func2,NULL); 
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    printf("\nThe Final Value of Shared Variable is %d\n",shared);
    return 0;
}

void *func1(){
    printf("\nIn Function 1\n");
    int x;
    sem_wait(&s);
    x = shared;
    x++;
    sleep(1);
    shared = x;
    sem_post(&s);
    printf("\nThe Value of Shared Variable (from x) is %d\n",shared);
    return NULL;
}

void *func2(){
    printf("\nIn Function 2\n");
    int y;
    sem_wait(&s);
    y = shared;
    y--;
    sleep(1);
    shared = y;
    sem_post(&s);
    printf("\nThe Value of Shared Variable (from y) is %d\n",shared);
    return NULL;
}