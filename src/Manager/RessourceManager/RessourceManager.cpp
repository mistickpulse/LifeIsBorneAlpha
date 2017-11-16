//
// Created by zouz on 14/11/17.
//

#include "RessourceManager.hpp"

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


