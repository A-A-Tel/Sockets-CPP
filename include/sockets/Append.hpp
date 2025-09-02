//
// Created by anthony on 01-09-2025.
//

#ifndef SOCKETS_APPEND_HPP
#define SOCKETS_APPEND_HPP
#include "Command.hpp"

class Append : public Command {
public:

    std::string get_name() override { return "append"; }

    std::string run(std::vector<std::string> args) override;
};

#endif //SOCKETS_APPEND_HPP