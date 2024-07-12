#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRINGS 3

void* concatenate(void* arg) {
    char** strings = (char**)arg;
    static char result[256] = "";

    for (int i = 0; i < NUM_STRINGS; i++) {
        strcat(result, strings[i]);
    }

    pthread_exit((void*)result);
}

int main() {
    pthread_t thread;
    char* strings[NUM_STRINGS] = {"Hello, ", "World", "!"};
    char* result;

    pthread_create(&thread, NULL, concatenate, (void*)strings);
    pthread_join(thread, (void**)&result);

    printf("Concatenated string: %s\n", result);
    return 0;
}
