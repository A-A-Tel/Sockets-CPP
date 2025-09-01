//
// Created by anthony on 29-08-2025.
//

#include "sockets/Echo.hpp"

std::string Echo::run(std::vector<std::string> args) {

    std::string output = " ";

    for (int i = 1; i < args.size(); ++i) output += args[i];

    return output;
}