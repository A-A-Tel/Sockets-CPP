//
// Created by anthony on 01-09-2025.
//

#include "../include/sockets/Append.hpp"

#include <fstream>

std::string Append::run(std::vector<std::string> args) {

    if (args.size() < 2) return "Too few arguments given";

    std::string append_text{};

    for (int i = 2; i < args.size(); ++i) append_text += args[i] + " ";

    std::ofstream file{args[1], std::ios::app};
    file << append_text;
    file.write(append_text.c_str(), append_text.size());
    file.close();
    return " Wrote " + std::to_string(append_text.length()) + " bytes of data to " + args[1];

}
