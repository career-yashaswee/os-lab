#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Thread function to calculate string length
void* string_length(void* arg) {
    char* str = (char*)arg;
    int length = strlen(str);
    printf("Length of string \"%s\" is %d\n", str, length);
    pthread_exit(NULL);
}

int main() {
    int num_strings = 3; // Number of strings
    char* strings[] = {"Hello, World!", "Pthreads are fun", "C programming"};

    pthread_t threads[num_strings];

    // Create threads
    for (int i = 0; i < num_strings; i++) {
        int result = pthread_create(&threads[i], NULL, string_length, (void*)strings[i]);
        if (result) {
            printf("Error creating thread %d: %d\n", i, result);
            exit(-1);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}
