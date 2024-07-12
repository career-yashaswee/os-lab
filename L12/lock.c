#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int shared = 1;
void *func1();
void *func2();

pthread_mutex_t l;

int main() {
    pthread_t th1;
    pthread_t th2;
    pthread_mutex_init(&l,NULL);
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
    pthread_mutex_lock(&l);
    x = shared;
    x++;
    sleep(1);
    shared = x;
    pthread_mutex_unlock(&l);
    printf("\nThe Value of Shared Variable (from x) is %d\n",shared);
    return NULL;
}

void *func2(){
    printf("\nIn Function 2\n");
    int y;
    pthread_mutex_lock(&l);
    y = shared;
    y--;
    sleep(1);
    shared = y;
    pthread_mutex_unlock(&l);
    printf("\nThe Value of Shared Variable (from y) is %d\n",shared);
    return NULL;
}