//
// Created by anthony on 29-08-2025.
//
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    const int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    char inet_address[16];
    scanf("%s", inet_address);


    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8084);
    server_address.sin_addr.s_addr = inet_addr(inet_address);
    fgets(inet_address, 0, stdin);

    connect(client_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));


    while (true) {
        char message[1024];
        fgets(message, 1024, stdin);
        send(client_socket, message, strlen(message), 0);

        if (strcmp(message, "exit\n") == 0) break;

        char buffer[1025];
        const long bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            std::cout << "Client received:" << buffer << std::endl;
        }
    }

    close(client_socket);

    return 0;
}
