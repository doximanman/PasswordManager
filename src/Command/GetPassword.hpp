//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_GETPASSWORD_HPP
#define PASSES_GETPASSWORD_HPP

#include "Command.hpp"

class GetPassword : public Command{
private:
    std::string path;
public:
    GetPassword(std::string dataPath);
    std::string description() override;
    std::string trigger() override;
    void execute(const std::vector<std::string>& args) override;
};


#endif //PASSES_GETPASSWORD_HPP
