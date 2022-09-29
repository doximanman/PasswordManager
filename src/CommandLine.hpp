//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_COMMANDLINE_HPP
#define PASSES_COMMANDLINE_HPP

#include "Command/Command.hpp"
#include <map>


class CommandLine {
private:

    std::map<std::string,Command*> commands;
public:
    explicit CommandLine(const std::string& path);
    void run();
    ~CommandLine();
};


#endif //PASSES_COMMANDLINE_HPP
