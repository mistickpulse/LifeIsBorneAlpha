//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGER_HPP
#define LIFEISBORNE_RESSOURCEMANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <bits/ios_base.h>
#include <ios>
#include "../../enum.h"

using SpriteBind = std::map<std::string, sf::Sprite>;

namespace {

    const unsigned int SpriteTypeQte = 1;

    std::array<std::string, 4> TexturesPath =
            {{
                     "../Ressources/intro/LifeIsBorneTitle.png",
                     "../Ressources/Textures/BodyParts/Chest/CarapuceChest.png",
                     "../Ressources/Textures/BodyParts/Head/CarapuceHead.png",
                     "../Ressources/Textures/BodyParts/Hat/CarapuceHat.png",
             }};


}

class RessourceManager {
public:
    static RessourceManager &getInstance() {
        static RessourceManager _Instance;
       return _Instance;
    }

    ~RessourceManager() = default;

    std::vector<sf::Sprite> &getSprite(const std::string &SpriteId);
private:
    RessourceManager();
   void _loadSprites();

private:

    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, std::vector<sf::Sprite>> _sprites;
};

#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
