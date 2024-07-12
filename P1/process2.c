#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    pid_t p1;
    p1 = fork();
    if(p1==0) {
        printf("\nI am Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());
         pid_t p2;
    p1 = fork();
    if(p2==0) {
        printf("\nI am Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());
         pid_t p1;
    p1 = fork();
    if(p1==0) {
        printf("\nI am Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());
    } else if(p1>0) {
        printf("\nI am Parent of Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());        
    } else {
        printf("\nError Creating Child Process P1\n");
    }
    } else if(p1>0) {
        printf("\nI am Parent of Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());        
    } else {
        printf("\nError Creating Child Process P1\n");
    }
    } else if(p1>0) {
        printf("\nI am Parent of Process P1\n");
        printf("\nMy Process ID: %d\n",getpid());
        printf("\nMy Parent Process ID: %d\n",getppid());        
    } else {
        printf("\nError Creating Child Process P1\n");
    }
}

