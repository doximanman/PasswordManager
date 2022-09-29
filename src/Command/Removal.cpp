//
// Created by kalo3 on 29-Sep-22.
//

#include "Removal.hpp"
#include "../StaticLib/TreeSerializer.hpp"
#include "../StaticLib/StringHandler.hpp"
#include <iostream>
#include <map>
#include <utility>

using namespace std;

Removal::Removal(string dataPath) : path(std::move(dataPath)) {
}

string Removal::description() {
    return "Remove an account or a whole site. First argument is the site. if one argument is provided, it deletes the site.";
}

string Removal::trigger() {
    return "remove";
}

void Removal::execute(const vector<string> &args) {
    map<string,map<string,string>> tree=TreeSerializer::deserialize(path);
    if(args.empty()){
        cout << "Not enough arguments for this command\nType 'help' to get help";
        return;
    }
    string site=StringHandler::convertSpaces(args[0]);
    if(args.size()==1){
        if(tree.count(site)==0){
            cout << "The site given has no accounts saved." << endl;
            return;
        }
        cout << "Are you sure you want to delete the site '"+site+"'? [Y/N] (default N)" << endl;
        char input;
        cin >> input;
        if(input=='Y'){
            tree.erase(site);
            cout << "Removal complete" << endl;
        }
        else if(input=='N'){
            cout << "Removal canceled" << endl;
            return;
        }
        else{
            cout << "Invalid input. Assuming N (default)" << endl;
        }
    }
    else{
        if(tree.count(site)==0){
            cout << "The site given has no accounts saved." << endl;
            return;
        }
        if(tree[site].count(args[1])==0){
            cout << "The username given doesn't exist for the given site." << endl;
            return;
        }
        tree[site].erase(args[1]);
        if(tree[site].empty()){
            tree.erase(site);
        }
        cout << "Removal complete" << endl;
    }
    TreeSerializer::serialize(tree,path);
}

