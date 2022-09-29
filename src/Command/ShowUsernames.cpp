//
// Created by kalo3 on 29-Sep-22.
//

#include <iostream>
#include <utility>
#include "ShowUsernames.hpp"
#include "../StaticLib/TreeSerializer.hpp"

using namespace std;

ShowUsernames::ShowUsernames(std::string dataPath) : path(std::move(dataPath)){}

std::string ShowUsernames::trigger() {
    return "show";
}

std::string ShowUsernames::description() {
    return "Shows the sites and usernames";
}
void ShowUsernames::execute(const std::vector<std::string>& args) {
    map<string,map<string,string>> tree=TreeSerializer::deserialize(path);
    if(tree.empty()){
        cout << "Empty." << endl;
        return;
    }
    if(!args.empty()){
        if(args[0]=="full"){
            cout << TreeSerializer::treeToString(TreeSerializer::deserialize(path));
        }
    }
    else {
        cout << TreeSerializer::treeToStringOnlyUsernames(TreeSerializer::deserialize(path));
    }
}