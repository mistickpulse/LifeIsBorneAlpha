//
// Created by zouz on 21/11/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "RessourceManager.hpp"


void RessourceManager::__loadCharacter(const std::string &FilePath) {
    std::ifstream istream(FilePath);
    json CharacterData;
    if (!istream) {
        std::cerr << "Unable to open file :" << FilePath << std::endl;
    }

    istream >> CharacterData;

    std::cout << std::endl;

    //Temporary adding variable this way.
    //std::cerr << CharacterData << std::endl;
    std::string characterName = CharacterData["Name"];
    std::cout << "Loading " << characterName << std::endl;
    std::vector<std::string> BodyParts = CharacterData["BodyParts"];

    for (const auto &i : BodyParts) {
        json bodyPartData = CharacterData[i];
        __loadBodyParts(characterName, bodyPartData, i);
    }
}

void RessourceManager::__loadTexturePackage(const std::string &characterName, const json &BodyPartData,
                                            const std::string &BodyPart) {
    json texturePackageData = BodyPartData["TexturePackage"];
    const std::vector<std::string> BodyPartTexturePaths = texturePackageData["Paths"];

    std::string Refkey("Character::");
    Refkey += characterName;
    Refkey += "::";
    Refkey += BodyPart;
    for (const auto &i : BodyPartTexturePaths) {
        std::string key(Refkey);

        key += "::" + i.substr(i.find_last_of('/') + 1, (i.find_last_of('.') - i.find_last_of('/') - 1));
//        std::cout << "MAPKEY:[" << key << "]" << std::endl;

        addTexture(key, i);
//        std::cout << i << std::endl;
    }
}

void RessourceManager::__loadBodyParts(const std::string &characterName, const json &BodyPartData,
                                       const std::string &BodyPart) {
    __loadTexturePackage(characterName, BodyPartData, BodyPart);
}
