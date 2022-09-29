//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_ADDACCOUNT_HPP
#define PASSES_ADDACCOUNT_HPP

#include "Command.hpp"

class AddAccount : public Command {
private:
    std::string path;
public:
    explicit AddAccount(std::string dataPath);
    std::string description() override;
    std::string trigger() override;
    void execute(const std::vector<std::string>& args) override;
};


#endif //PASSES_ADDACCOUNT_HPP
