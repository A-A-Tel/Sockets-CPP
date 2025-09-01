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

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));

    char message[1024];
    scanf("%s", message);
    send(client_socket, message, strlen(message), 0);

    char buffer[1024];
    const long bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        std::cout << "Client received: ec" << buffer << std::endl;
    }

    close(client_socket);

    return 0;
}
