//
// Created by anthony on 29-08-2025.
//
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "sockets/Command.hpp"
#include "sockets/Echo.hpp"

const std::vector<Command *> commands = {new Echo()};

/**
 * This searches for a command matching its name and returns the output, or an error if the command does not exist.
 *
 * @return char *
 * @param command_input a <code>const std::string</code> containing the full command input
 */
std::string use_command(const std::string &command_input) {

    std::vector<std::string> tokens;
    boost::split(tokens, command_input, boost::is_any_of(" "), boost::token_compress_off);



    if (!tokens.empty()) for (Command *command : commands) {
        if (command->name == tokens[0]) return command->run(tokens);
    }
    return "command does not exist";
}

int main() {

    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8082);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));


    listen(server_socket, 4096);


    sockaddr_in client_address{};
    socklen_t client_len = sizeof(client_address);
    const int client_socket = accept(server_socket, reinterpret_cast<struct sockaddr *>(&client_address), &client_len);


    while (true) {

        char buffer[1025];
        const long bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            if (strcmp(buffer, "exit\n") == 0) break;


            std::string str_output = use_command(buffer);

            const char *output = str_output.c_str();
            send(client_socket, output, strlen(output), 0);
        }
    }


    close(client_socket);
    close(server_socket);

    return 0;
}
