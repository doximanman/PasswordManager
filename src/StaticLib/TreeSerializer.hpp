//
// Created by kalo3 on 29-Sep-22.
//

#ifndef PASSES_TREESERIALIZER_HPP
#define PASSES_TREESERIALIZER_HPP

#include <string>
#include <map>

class TreeSerializer {
public:
    static std::string treeToStringOnlyUsernames(const std::map<std::string,std::map<std::string,std::string>>& tree);
    static std::string treeToString(const std::map<std::string,std::map<std::string,std::string>>& tree);
    static void serialize(const std::map<std::string,std::map<std::string,std::string>>& tree,const std::string& path);
    static std::map<std::string,std::map<std::string,std::string>> deserialize(const std::string& path);
};


#endif //PASSES_TREESERIALIZER_HPP
