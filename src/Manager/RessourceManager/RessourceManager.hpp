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
#include "../../../Submodules/json/src/json.hpp" // To change

using SpriteBind = std::map<std::string, sf::Sprite>;
using LoadBehavior = std::function<void(const std::string &)>;
using namespace nlohmann;

namespace {

    /*
     *  Format
     *  Character Sprite
     *  "Charcter::CharacterName::BodyPart"
     *
     *  Spell
     *  "Spell::SPellType::Type(Attack/Defense)"
     */

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
    void load();

private:
    RessourceManager();
    void _loadBehaviors();
    void _loadSprites();


    /*
     * Loaders
     */

private://Character
    void __loadCharacter(const std::string FilePath);

    void __loadBodyParts(const json &character, const std::string &BodyPart);

private://Scenery
    void __loadScenery(const std::string FilePath);

private://Spells
    void __loadSpell(const std::string FilePath);


private: //LoaderLore

private:

    std::vector<std::pair<TypeLoaded, LoadBehavior>> _loadBehavior;
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, std::vector<sf::Sprite>> _sprites;
};

#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
