//
// Created by anthony on 29-08-2025.
//

#ifndef SOCKETS_COMMAND_HPP
#define SOCKETS_COMMAND_HPP

#include <string>
#include <vector>

class Command {

public:
    virtual ~Command() = default;


    const std::string name;


    virtual std::string run(std::vector<std::string> args) = 0;
};


#endif //SOCKETS_COMMAND_HPP