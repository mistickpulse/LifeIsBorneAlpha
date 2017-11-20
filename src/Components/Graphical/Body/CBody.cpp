//
// Created by zouz on 16/11/17.
//

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "CBody.hpp"


CBody::CBody(const std::vector<std::pair<BodyPartType, std::string>> &BodyInformation):
        AComponent(typeid(CBody).name()) {
    for (const auto &i : BodyInformation) {
       _addBodyPart(i.first, i.second);
    }

}


const std::vector <sf::Sprite> &CBody::getBodySprites(Orientation direction) {
}

void CBody::_deleteBodyPart(BodyPartType typeToDel) {
    for (auto i = _bParts.begin(); i != _bParts.end(); ++i) {
        if (i->getBodyType() == typeToDel) {
            _bParts.erase(i);
        }
    }
}

void CBody::changeBodyPart(BodyPartType newBodyPartType, const std::string &CharacterName) {
    _deleteBodyPart(newBodyPartType);

}

void CBody::_addBodyPart(BodyPartType newBodyPart, const std::string &CharacterName) {
    /*
     * Call the Body Part Factory for each pair of the "BodyInformation" vector with name + BodyPartType (pair.second, pair.first);
     */
    BodyPart *tmp = nullptr; // Assign to the return of the BodyPart Factory (change for a &);
    _bParts.emplace_back(*tmp);
}

