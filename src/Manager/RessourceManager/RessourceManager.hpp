//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGER_HPP
#define LIFEISBORNE_RESSOURCEMANAGER_HPP

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <bits/ios_base.h>
#include <functional>
#include "TypeLoaded.hpp"
#include "../../enum.h"

using SpriteBind = std::map<std::string, sf::Sprite>;
using LoadBehavior = std::function<void(const std::string &)>;

namespace {

    /*
     *  Format
     *  Character Sprite
     *  "Charcter::CharacterName::BodyPart"
     *
     *  Spell
     *  "Spell::SPellType::Type(Attack/Defense)"
     */

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

public:
    std::vector<sf::Sprite> &getSprite(const std::string &SpriteId);
    void addRessources(const std::string &filePath, TypeLoaded type);
    void addLoadBehavior(TypeLoaded type, LoadBehavior &lb, bool replace=false);

private:
    RessourceManager();
   void _loadSprites();

private:

    std::vector<std::pair<TypeLoaded, LoadBehavior>> _loadBehavior;
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, std::vector<sf::Sprite>> _sprites;
};

#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
