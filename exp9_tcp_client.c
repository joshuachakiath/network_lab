
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9000
#define BUFFER_SIZE 1024
#define NAME_SIZE 30

int main()
{
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server,
                sizeof(server)) < 0) {
        printf("Connection Failed\n");
        close(sock);
        return 1;
    }

    // Enter client name
    char name[NAME_SIZE];

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        close(sock);
        return 1;
    }

    name[strcspn(name, "\r\n")] = '\0';

    // Send name to server
    if (send(sock, name, strlen(name) + 1, 0) <= 0) {
        close(sock);
        return 1;
    }

    printf("\nConnected to Chat Server\n");
    printf("Type your messages below\n\n");

    if (fork() == 0) {
        // Child process: sender
        char message[BUFFER_SIZE];

        while (fgets(message, sizeof(message), stdin) != NULL) {
            if (send(sock, message, strlen(message), 0) <= 0)
                break;
        }

        shutdown(sock, SHUT_WR);
        close(sock);
        exit(0);
    }
    else {
        // Parent process: receiver
        char buffer[BUFFER_SIZE];

        while (1) {
            int n = recv(sock, buffer,
                         sizeof(buffer) - 1, 0);

            if (n <= 0) {
                printf("\nDisconnected from Server\n");
                break;
            }

            buffer[n] = '\0';
            printf("%s", buffer);
            fflush(stdout);
        }
    }

    close(sock);
    return 0;
}
