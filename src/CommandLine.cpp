//
// Created by kalo3 on 29-Sep-22.
//

#include "CommandLine.hpp"
#include "Command/ShowUsernames.hpp"
#include "Command/AddAccount.hpp"
#include "Command/GetPassword.hpp"
#include "Command/Removal.hpp"
#include "StaticLib/StringHandler.hpp"
#include <iostream>

using namespace std;

CommandLine::CommandLine(const std::string& path) :commands(){
    Command* show=new ShowUsernames(path);
    Command* add=new AddAccount(path);
    Command* get=new GetPassword(path);
    Command* remove=new Removal(path);
    commands[show->trigger()]=show;
    commands[add->trigger()]=add;
    commands[get->trigger()]=get;
    commands[remove->trigger()]=remove;
}

void CommandLine::run() {
    cout << "Welcome to the password manager! Type 'help' to see available commands." << endl;
    string input;
    getline(cin,input);
    cin.clear();
    vector<string> commandWithArgs= StringHandler::spaceSeparation(input);
    while(commandWithArgs.empty()||commandWithArgs[0]!="exit"){
        if(!commandWithArgs.empty()){
            if(commandWithArgs[0]=="help"){
                cout << "Commands:" << endl;
                for(auto& com : commands){
                    cout << "\t"+com.second->trigger()+ ": " +com.second->description() << endl;
                }
            }
            else if(commands.count(commandWithArgs[0])==0){
                cout << "Command not found." << endl;
            }
            else {
                vector<string> args{commandWithArgs.begin() + 1, commandWithArgs.end()};
                commands[commandWithArgs[0]]->execute(args);
            }
        }
        getline(cin,input);
        cin.clear();
        commandWithArgs= StringHandler::spaceSeparation(input);
    }
}


CommandLine::~CommandLine() {
    for(const auto& command:commands){
        delete command.second;
    }
}