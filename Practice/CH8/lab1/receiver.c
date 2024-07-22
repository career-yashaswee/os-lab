// receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#define SEND_PIPE "send_pipe"
#define RECEIVE_PIPE "receive_pipe"

int main() {
    int send_fd, receive_fd;
    char send_message[100];
    char response_message[100] = "Message received!";

    // Create the named pipes (FIFOs) if they do not exist
    mkfifo(SEND_PIPE, 0666);
    mkfifo(RECEIVE_PIPE, 0666);

    // Open the send pipe for reading
    send_fd = open(SEND_PIPE, O_RDONLY);
    if (send_fd == -1) {
        perror("open send_pipe");
        exit(EXIT_FAILURE);
    }

    // Read the message from the send pipe
    read(send_fd, send_message, sizeof(send_message));

    // Print the received message
    printf("Received message: %s\n", send_message);

    // Close the send pipe
    close(send_fd);

    // Open the receive pipe for writing
    receive_fd = open(RECEIVE_PIPE, O_WRONLY);
    if (receive_fd == -1) {
        perror("open receive_pipe");
        exit(EXIT_FAILURE);
    }

    // Write the response to the receive pipe
    write(receive_fd, response_message, strlen(response_message) + 1);

    // Close the receive pipe
    close(receive_fd);

    return 0;
}
