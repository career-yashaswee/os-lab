#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int shared = 1;
void *func1();
void *func2();

int main() {
    pthread_t th1;
    pthread_t th2;
    printf("\nInside a Main Function\n");
    pthread_create(&th1,NULL,*func1,NULL);
    pthread_create(&th2,NULL,*func2,NULL); 
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    printf("\nThe Value of Shared Variable is %d\n",shared);
    return 0;
}

void *func1(){
    int x = shared;
    x++;
    sleep(1);
    shared = x;
    return NULL;
    //printf("\nThe Value of Shared Variable is %d\n",shared);
    return NULL;
}

void *func2(){
    int y = shared;
    y--;
    sleep(1);
    shared = y;
    
    //printf("\nThe Value of Shared Variable is %d\n",shared);
    return NULL;
}