//
// Created by zouz on 14/11/17.
//

#include <iostream>
#include <fstream>
#include "../../enum.h"
#include "RessourceManager.hpp"
#include "RessourceManagerException.hpp"


RessourceManager::RessourceManager() {
}

std::vector<sf::Sprite> &RessourceManager::getSprite(const std::string &SpriteId) {
}

void RessourceManager::addLoadBehavior(TypeLoaded type, LoadBehavior &lb, bool replace) {
    //TODO
    //call the logManager for every output print
    std::cerr << "[LoadBehavior]:adding [" << type._to_string() << "] Load Behavior" << std::endl;
    for (const auto &i : _loadBehavior) {
        if (i.first == type && !replace) {
            std::string tmp("[Error]:[");
            tmp += type._to_string();
            tmp += "] Already loaded\n";
            throw LoadingError(tmp);
        }
    }
    _loadBehavior.push_back(std::make_pair(type, lb));
    if (!replace) {
        std::cerr << "[Successfully adding load behavior]:" << type._to_string() << std::endl;
    }
    else {
        std::cerr << "[Successfully replacing load behavior]:" << type._to_string() << std::endl;
    }
}

void RessourceManager::addRessources(const std::string &filePath, TypeLoaded type) {
    //TODO same here (see the function below)

    std::cout << "  Loading [" << filePath<< "]: ";
    for (const auto &i : _loadBehavior) {
        if (type == i.first) {
            i.second(filePath);
            std::cout << "OK" << std::endl;
            return ;
        }
    }
    std::cout << "KO:" << std::endl << "\tReason: Unknow Ressource Type load Behavior" << std::endl;
}




void RessourceManager::load() {
    _loadBehaviors();
}


/*
 * Loaders
 */

void RessourceManager::_loadBehaviors() {
    using namespace std::placeholders;
    std::function<void(const std::string &)> tmp = std::bind(&RessourceManager::__loadCharacter, this, _1);

    addLoadBehavior(TypeLoaded::Character, tmp);
}

void RessourceManager::addTexture(const std::string &key, const std::string &TexturePath) {
    sf::Texture tmp;
    if (tmp.loadFromFile(std::string(RessourcePath + TexturePath)) == false) {
        return;
    }

    std::cout << "  Loading Textures: " << TexturePath << std::endl;
    _textures.insert(std::make_pair(key, std::move(tmp)));
}

