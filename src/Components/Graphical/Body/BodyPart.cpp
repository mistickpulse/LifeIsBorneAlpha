//
// Created by zouz on 16/11/17.
//

#include "BodyPartType.hpp"
#include "BodyPart.hpp"
#include "../../../Utils/Size.hpp"

std::vector<sf::Sprite> &BodyPart::getBodySprite(Orientation bodyOrientation) {
    for (int i = 0; i < Orientation::ORIENTATION_QTE; ++i) {
        if (_sprites[i].first == bodyOrientation) {
            return _sprites[i].second;
        }
    }
}

BodyPart &BodyPart::operator=(const BodyPart &src) {
    _sprites = src._sprites;
    static_cast<Size>(_canvas) = src._canvas;
    _type = src._type;
}

BodyPart::BodyPart(BindDirectionVSprite &SpriteSrc, BodyPartType type, const Size &canvasSize):
    _sprites(SpriteSrc), _type(type), _canvas(canvasSize){}

