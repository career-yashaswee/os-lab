// sender.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEND_PIPE "send_pipe"
#define RECEIVE_PIPE "receive_pipe"

int main() {
    int send_fd, receive_fd;
    char send_message[100];
    char receive_message[100];

    // Create the named pipes (FIFOs) if they do not exist
    mkfifo(SEND_PIPE, 0666);
    mkfifo(RECEIVE_PIPE, 0666);

    // Get the message to send
    printf("Enter the message to send: ");
    fgets(send_message, sizeof(send_message), stdin);
    send_message[strcspn(send_message, "\n")] = '\0'; // Remove newline character if present

    // Open the send pipe for writing
    send_fd = open(SEND_PIPE, O_WRONLY);
    if (send_fd == -1) {
        perror("open send_pipe");
        exit(EXIT_FAILURE);
    }

    // Write the message to the send pipe
    write(send_fd, send_message, strlen(send_message) + 1);

    // Close the send pipe
    close(send_fd);

    // Open the receive pipe for reading
    receive_fd = open(RECEIVE_PIPE, O_RDONLY);
    if (receive_fd == -1) {
        perror("open receive_pipe");
        exit(EXIT_FAILURE);
    }

    // Read the response from the receive pipe
    read(receive_fd, receive_message, sizeof(receive_message));

    // Print the received message
    printf("Received response: %s\n", receive_message);

    // Close the receive pipe
    close(receive_fd);

    return 0;
}
