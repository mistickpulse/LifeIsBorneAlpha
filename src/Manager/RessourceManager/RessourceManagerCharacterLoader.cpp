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
        return;
    }

    istream >> CharacterData;

    std::cout << std::endl;

    std::string characterName = CharacterData["Name"];
    std::cout << "Loading " << characterName << std::endl;
    std::vector<std::string> BodyParts = CharacterData["BodyParts"];
    const Size canvas{CharacterData["Canvas"][0], CharacterData["Canvas"][1]};

    for (const auto &bodyPartName : BodyParts) {
        json bodyPartData = CharacterData[bodyPartName];
        __loadBodyParts(characterName, bodyPartData, bodyPartName, canvas);
    }
}

void RessourceManager::__loadTexturePackage(const std::string &characterName, const json &BodyPartData,
                                            const std::string &BodyPart, const Size &canvas) {
    std::flush(std::cout);
    json texturePackageData = BodyPartData["TexturePackage"];
    const std::vector<json> BodyPartTexturePackagePaths = texturePackageData["Paths"];

    std::string Refkey("Character::");
    Refkey += characterName;
    Refkey += "::";
    Refkey += BodyPart;
    for (auto &i : BodyPartTexturePackagePaths) {
        std::string TexturePath = i["Path"];
        std::string key(Refkey);

        key += "::" + TexturePath.substr(TexturePath.find_last_of('/') + 1,
                                         (TexturePath.find_last_of('.') - TexturePath.find_last_of('/') - 1));
        std::cout << "MapKey:[" << key << "]" << std::endl;
        if (addTexture(key, TexturePath) == true) {
            std::cout << "  Loading Sprites:";
            __loadSprites(key, i["KeyWord"], canvas, i["SpritesQte"]);
        }
    }
}

void RessourceManager::__loadSprites(const std::string &PrebuildKey, const std::string &Keyword, const Size &canvas,
                                     int SprQte) {
    sf::Texture &txt = _textures[PrebuildKey];
    std::string newKey(std::move(PrebuildKey + "::" + Keyword));
    std::vector<sf::Sprite> toPush;

    Position pos{0, 0};
    while (SprQte > 0) {
        sf::Sprite spr(txt);
        spr.setTextureRect({pos.x, pos.x, static_cast<int>(canvas.width), static_cast<int>(canvas.height)});
        toPush.push_back(std::move(spr));
        pos.x += canvas.width;
        --SprQte;
    }
    _sprites.insert(std::make_pair(newKey, std::move(toPush)));
}

void RessourceManager::__loadBodyParts(const std::string &characterName, const json &BodyPartData,
                                       const std::string &BodyPart, const Size &canvas) {
    __loadTexturePackage(characterName, BodyPartData, BodyPart, canvas);
}
