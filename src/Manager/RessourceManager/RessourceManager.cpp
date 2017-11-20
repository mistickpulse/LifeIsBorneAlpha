//
// Created by zouz on 14/11/17.
//

#include <iostream>
#include "RessourceManager.hpp"
#include "RessourceManagerException.hpp"

RessourceManager::RessourceManager() {
    for (const auto &i : TexturesPath) {
        sf::Texture tmp;
        tmp.loadFromFile(i);
       _textures.insert(std::make_pair(i, std::move(tmp)));
    }
    _loadSprites();
}

void RessourceManager::_loadSprites() {
}

std::vector<sf::Sprite> &RessourceManager::getSprite(const std::string &SpriteId) {
}

void RessourceManager::addLoadBehavior(TypeLoaded type, LoadBehavior &lb, bool replace) {
    //TODO
    //call the logManager for every output print
    std::cerr << "[LoadBehavior]:Try to add a Load Behavior" << std::endl;
    for (const auto &i : _loadBehavior) {
        if (i.first == type && !replace) {
            std::string tmp("[Already Loaded Type Behavior]:[");
            tmp += type._to_string();
            tmp += "] Already loaded";
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

    std::cerr << "[RessourcesLoading]:Try to Load Resources: " << filePath << std::endl;
    for (const auto &i : _loadBehavior) {
        if (type == i.first) {
            i.second(filePath);
            std::cerr << "[RessourcesLoading]:Ressource successfully loaded:" << filePath << std::endl;
            return ;
        }
    }
    std::cerr << "[RessourcesLoading]:" << "Failing to load " << filePath << " Reason:" << "Unknow Type Behavior" << std::endl;
}
