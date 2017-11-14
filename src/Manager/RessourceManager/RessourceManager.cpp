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
    std::vector<sf::Sprite> sheets;

    sf::Sprite Stmp(_textures[TexturesPath[1]]);
    Stmp.setTextureRect({0, 0, 28, 31});
    sheets.emplace_back(sf::Sprite(Stmp));
    _sprites.insert(std::make_pair("CarapuceChest", std::vector<sf::Sprite>(sheets)));

    Stmp.setTexture(_textures[TexturesPath[2]]);
    sheets.clear();

    Stmp.setTextureRect({0, 0, 22, 22});
    sheets.emplace_back(sf::Sprite(Stmp));

    Stmp.setTextureRect({23, 0, 22, 22});
    sheets.emplace_back(sf::Sprite(Stmp));
    _sprites.insert(std::make_pair("CarapuceHead", std::vector<sf::Sprite>(sheets)));

}

std::vector<sf::Sprite> &RessourceManager::getSprite(const std::string &SpriteId) {
    return _sprites[SpriteId];
}


