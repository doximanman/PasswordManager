//
// Created by kalo3 on 29-Sep-22.
//

#include "../StaticLib/TreeSerializer.hpp"
#include "AddAccount.hpp"
#include "../StaticLib/StringHandler.hpp"
#include <iostream>
#include <utility>
#include <map>

using namespace std;

AddAccount::AddAccount(std::string dataPath) : path(std::move(dataPath)) {
}

std::string AddAccount::description() {
    return "Add an account. needs 3 arguments, first argument is the site, second argument is the username,"
           " and 3rd is the password.";
}

std::string AddAccount::trigger() {
    return "add";
}

void AddAccount::execute(const std::vector<std::string> &args) {
    if (args.size() < 3) {
        cout << "Not enough arguments for this command\nType 'help' to get help" << endl;
        return;
    }
    string site=StringHandler::convertSpaces(args[0]);
    map<string, map<string, string>> tree = TreeSerializer::deserialize(path);
    tree[site][args[1]]=args[2];
    TreeSerializer::serialize(tree,path);
    cout << "Addition complete" << endl;
}