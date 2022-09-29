//
// Created by kalo3 on 29-Sep-22.
//

#include "TreeSerializer.hpp"
#include <fstream>

using namespace std;

std::string
TreeSerializer::treeToStringOnlyUsernames(const std::map<std::string, std::map<std::string, std::string>> &tree) {
    string result;
    for(auto& site : tree){
        result.append(site.first+":\n");
        for(auto& account : site.second){
            result.append("\t"+account.first+"\n");
        }
    }
    return result;
}

string TreeSerializer::treeToString(const map<string,map<string, string>>& tree) {
    string result;
    for(auto& site : tree){
        result.append(site.first+":\n");
        for(auto& account : site.second){
            result.append("\t"+account.first+"\t"+account.second+"\n");
        }
    }
    return result;
}

void TreeSerializer::serialize(const map<string,map<string, string>>& tree, const string& path) {
    remove(path.c_str());
    ofstream str(path);
    str << treeToString(tree);
    str.close();
}

map<string,map<string, string>> TreeSerializer::deserialize(const std::string& path) {
    map<string,map<string, string>> tree;
    ifstream str(path);
    string line;
    while(getline(str,line)){
        // removes possible \r
        if(!line.empty()&&line[line.size()-1]=='\r'){
            line.pop_back();
        }
        if(line.size()<2||line[line.size()-1]!=':'||line[0]=='\t'){
            continue;
        }
        // removes the : ending to get the site name.
        line.pop_back();
        string site=line;
        tree[line]=map<string,string>{};
        while((char)str.peek()=='\t'&&getline(str,line)){
            // removes possible \r
            if(!line.empty()&&line[line.size()-1]=='\r'){
                line.pop_back();
            }
            if(line.size()<2){
                continue;
            }
            // removes the starting tab
            string account=line.substr(1,line.size());
            auto tab=account.find('\t');
            tree[site][account.substr(0,tab)]=account.substr(tab+1,account.size());
        }
    }
    return tree;
}