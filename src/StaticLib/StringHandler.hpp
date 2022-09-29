//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_STRINGHANDLER_HPP
#define PASSES_STRINGHANDLER_HPP

#include <string>
#include <vector>

class StringHandler {
public:
    static std::vector<std::string> spaceSeparation(const std::string& line);
    static std::string convertSpaces(const std::string& s);
};


#endif //PASSES_STRINGHANDLER_HPP
