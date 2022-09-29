//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_REMOVAL_HPP
#define PASSES_REMOVAL_HPP

#include "Command.hpp"

class Removal :public Command{
private:

    std::string path;
public:
    explicit Removal(std::string dataPath);
    std::string description() override;
    std::string trigger() override;
    void execute(const std::vector<std::string>& args) override;
};


#endif //PASSES_REMOVAL_HPP
