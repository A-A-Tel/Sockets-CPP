//
// Created by anthony on 29-08-2025.
//

#ifndef SOCKETS_ECHO_HPP
#define SOCKETS_ECHO_HPP
#include "Command.hpp"


class Echo : public Command {
public:

    std::string get_name() override { return "echo"; }


    std::string run(std::vector<std::string> args) override;
};


#endif //SOCKETS_ECHO_HPP