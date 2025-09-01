//
// Created by anthony on 29-08-2025.
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

int main() {

    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));

    listen(server_socket, 5);

    sockaddr_in client_address{};
    socklen_t client_len = sizeof(client_address);
    const int client_socket = accept(server_socket, reinterpret_cast<sockaddr *>(&client_address), &client_len);

    char buffer[1024];
    const long bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        std::cout << "Client connected: %s\n" << buffer << std::endl;
    }

    const char *message = "Hello World!\n";
    send(client_socket, message, strlen(message), 0);

    close(client_socket);
    close(server_socket);

    return 0;
}
