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

    const Size canvas{CharacterData["Canvas"][0], CharacterData["Canvas"][1]};

    std::string CanvasKey("Character::");
    CanvasKey += characterName;
    _canvas.insert(std::make_pair(CanvasKey, canvas));
    __loadBodyParts(characterName, CharacterData, canvas);

}

void RessourceManager::__loadBodyParts(const std::string &CharacterName, json &CharacterData, const Size &canvas) {
    //need to register BodyPart in BodyPartFactory;
    BodyPartLoader loader;


    loader.CharacterName = CharacterName;
    loader.canvas = canvas;
    loader.AnimationType = CharacterData["AnimationType"];
    BindDirectionVSprite BpGraphics;

    for (const auto &bodyPartName : CharacterData["BodyParts"]) {
        json bodyPartData = CharacterData[bodyPartName];
        loader.BodyPart = bodyPartName;
        loader.SpriteQte = bodyPartData["SpriteQte"];
        __loadBodyPart(bodyPartData, loader);
    }
}

void RessourceManager::__loadBodyPart(json &BodyPartData, BodyPartLoader &bpLoader) {
    json TexturePackageData = BodyPartData["TexturePackage"];
    for (const auto &animationType : bpLoader.AnimationType) {
        json AnimationTypeData = TexturePackageData[animationType];
        AnimationLoader toFill;
        toFill.AnimationType = animationType;
        __loadAnimation(bpLoader, toFill, AnimationTypeData);
    }
}

void RessourceManager::__loadAnimation(BodyPartLoader &bpLoader, AnimationLoader &toFill, json &AnimationTypeData) {
    toFill.ADuration = std::chrono::milliseconds(AnimationTypeData["AnimationDuration"]);
    std::vector<std::string> TexturePath = AnimationTypeData["Paths"];

    __loadTextures(bpLoader, toFill, TexturePath);

/*    Character::Boris::Hair::Basic::FrontLeft */
    for (const auto &textureKey : bpLoader.TextureKeys) {
        std::vector<sf::Sprite *> sprites;
        std::string Orientation = textureKey.substr(textureKey.find_last_of(':') + 1, textureKey.size());
        __loadSprites(toFill, textureKey, Orientation);
    }
}

void RessourceManager::__loadSprites(BodyPartLoader &bpLoader, AnimationLoader &toFill, const std::string TextureKey,
                                     const std::string &Orientation) {
    sf::Texture &txt = *_textures[TextureKey];
    std::vector<sf::Sprite *> toPush;

    Position pos{0, 0};
    for (int i = 0; i < bpLoader.SpriteQte; ++i) {
        sf::Sprite *spr = new sf::Sprite(txt);
        spr->setTextureRect(
                {pos.x, pos.x, static_cast<int>(bpLoader.canvas.width), static_cast<int>(bpLoader.canvas.height)});
        toPush.push_back(spr);
        pos.x += bpLoader.canvas.width;
    }
    std::cout << "      adding Animation:" << TextureKey << std::endl;
    _sprites.insert(std::make_pair(TextureKey, std::move(toPush)));
    for (Orientation dir : Orientation::_values()) {
        if (dir._to_string() == Orientation) {
//            toFill.Sprites->insert(std::make_pair(dir, _sprites[TextureKey]));
        }
    }

}

void RessourceManager::__loadTextures(BodyPartLoader &bpLoader, AnimationLoader &aLoader,
                                      const std::vector<std::string> &TexturePaths) {

    std::string Refkey("Character::");
    Refkey += bpLoader.CharacterName;
    Refkey += "::";
    Refkey += aLoader.AnimationType;
    Refkey += "::";
    Refkey += bpLoader.BodyPart;
    for (const auto &path : TexturePaths) {
        std::string key(Refkey);
        std::string Orientation = path.substr(path.find_last_of('/') + 1,
                                              (path.find_last_of('.') - path.find_last_of('/') - 1));
        key += "::" + Orientation;

        if (addTexture(key, path) == true) {
            std::cout << "MapKey:[" << key << "]" << std::endl;
            bpLoader.TextureKeys.push_back(key);
        }
    }
}

