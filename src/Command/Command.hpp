//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_COMMAND_HPP
#define PASSES_COMMAND_HPP

#include <string>
#include <vector>

class Command {
public:
    virtual std::string description()=0;
    virtual std::string trigger()=0;
    virtual void execute(const std::vector<std::string>& args)=0;
    virtual ~Command()= default;
};


#endif //PASSES_COMMAND_HPP
