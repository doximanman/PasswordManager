//
// Created by kalo3 on 29-Sep-22.
//

#include "StringHandler.hpp"
#include <sstream>

using namespace std;

std::vector<std::string> StringHandler::spaceSeparation(const std::string &line) {
    stringstream str(line);
    string arg;
    vector<string> args;
    while(getline(str,arg,' ')){
        args.push_back(arg);
    }
    return args;
}

std::string StringHandler::convertSpaces(const std::string& s) {
    stringstream str(s);
    string result;
    string currentWord;
    while(getline(str,currentWord,'_')){
        result.append(currentWord+' ');
    }
    if(!result.empty()){
        result.pop_back();
    }
    return result;
}