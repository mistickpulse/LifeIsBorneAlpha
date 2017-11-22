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
#include "../../Utils/Position.hpp"

using LoadBehavior = std::function<void(const std::string &)>;
using namespace nlohmann;

namespace {

    const std::string RessourcePath = "../";
    /*
     *  Format
     *  Character Sprite
     *  "Character::CharacterName::BodyPart::Direction"
     *
     *  Spell
     *  "Spell::SpellType::Type(Attack/Defense)"
     *
     *  Scenery
     *  "Scenery::SceneryType::Name"
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

    void addTexture(const std::string &key, const std::string &TexturePath);
    void load();


private:
    RessourceManager();
    void _loadBehaviors();

    /*
     * Loaders
     */

private://Character
    void __loadCharacter(const std::string &FilePath);

    void __loadBodyParts(const std::string &characterName, const json &character, const std::string &BodyPart);

private://Scenery
    void __loadScenery(const std::string FilePath);

private://Spells
    void __loadSpell(const std::string FilePath);


private://LoaderLore
    void __loadTexturePackage(const std::string &characterName, const json &character, const std::string &BodyPart);

private:

    std::vector<std::pair<TypeLoaded, LoadBehavior>> _loadBehavior;
    std::map<std::string, sf::Texture> _textures;
    //std::map<std::string, std::vector<sf::Sprite>> _sprites;
    std::map<std::string, Position> _canvas;
};

#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
