#include <unistd.h>

int main() {
    char BUFFER[50];
    int n;
    n = read(0,BUFFER,50);
    write(1,BUFFER,n);
}