//
// Created by zouz on 21/11/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "RessourceManager.hpp"


void RessourceManager::__loadCharacter(const std::string FilePath) {
    std::ifstream istream(FilePath);
    json CharacterData;
    if (!istream) {
        std::cerr << "Unable to open file :" << FilePath << std::endl;
    }

    istream >> CharacterData;

    std::cout << std::endl;
    //Temporary adding variable this way.
//    std::cerr << CharacterData << std::endl;
    std::string CharacterName = CharacterData["Name"];
    std::cout << "CharacterName:" << CharacterName << std::endl;
    std::vector<std::string> BodyParts = CharacterData["BodyParts"];

    for (const auto &i : BodyParts) {
        __loadBodyParts(CharacterData, i);
    }
}

void RessourceManager::__loadBodyParts(const json &character, const std::string &BodyPart) {
    std::cout << "============ Loading [" << BodyPart << "] ===========" << std::endl;
    json BodyPartObject = character[BodyPart];
    std::vector<std::string> BodyPartTexture = BodyPartObject["Path"];
    for (const auto &i : BodyPartTexture) {
        std::cerr << i << std::endl;
    }
    std::cout << "============ End loading [" << BodyPart << "] ===========" << std::endl;
}

