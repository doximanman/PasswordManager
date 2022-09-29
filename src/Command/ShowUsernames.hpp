//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_SHOWUSERNAMES_HPP
#define PASSES_SHOWUSERNAMES_HPP

#include "Command.hpp"
#include <map>

class ShowUsernames : public Command{
private:
    std::string path;
public:
    explicit ShowUsernames(std::string  dataPath);
    std::string description() override;
    std::string trigger() override;
    void execute(const std::vector<std::string>& args) override;
};


#endif //PASSES_SHOWUSERNAMES_HPP
