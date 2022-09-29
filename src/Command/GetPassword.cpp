//
// Created by kalo3 on 29-Sep-22.
//

#include "GetPassword.hpp"
#include "../StaticLib/TreeSerializer.hpp"
#include "../StaticLib/StringHandler.hpp"
#include <iostream>
#include <utility>

using namespace std;

GetPassword::GetPassword(string dataPath) : path(std::move(dataPath)) {
}

string GetPassword::description() {
    return "Get the password of an account. First argument is the site, and the second argument is the account username.";
}

string GetPassword::trigger() {
    return "get";
}

void GetPassword::execute(const vector<string> &args) {
    if (args.size() < 2) {
        cout << "Not enough arguments for this command\nType 'help' to get help" << endl;
    } else {
        string site=StringHandler::convertSpaces(args[0]);
        map<string, map<string, string>> tree = TreeSerializer::deserialize(path);
        if (tree.count(site) == 0) {
            cout << "The site given has no accounts saved." << endl;
        } else if (tree[site].count(args[1]) == 0) {
            cout << "The username given doesn't exist for the given site." << endl;
        } else {
            cout << tree[site][args[1]] << endl;
        }
    }
}