//
// Created by zouz on 16/11/17.
//

#include "BodyPartType.hpp"
#include "GraphicalBodyPart.hpp"

GraphicalBodyPart &GraphicalBodyPart::operator=(const GraphicalBodyPart &src) {
    _sprites = src._sprites;
    static_cast<Size>(_canvas) = src._canvas;
    _type = src._type;
}

sf::Sprite &GraphicalBodyPart::getAnimationSprite(Orientation bodyOrientation) {
    int offset = 0;

    offset = (_AnimationCurrentTick / _AnimationTick) % _sprites[0].second.size();
    for (auto &i : _sprites) {
        if (i.first == bodyOrientation) {
            return i.second[offset];
        }
    }
}

GraphicalBodyPart::GraphicalBodyPart(BindDirectionVSprite &SpriteSrc, BodyPartType type, const Size &canvasSize,
                                     const std::chrono::milliseconds &ADuration) :
        _sprites(SpriteSrc),
        _type(type),
        _canvas(canvasSize),
        _AnimationDuration(ADuration),
        _AnimationCurrentTick(0),
        _AnimationTick(_AnimationDuration / _sprites[0].second.size()) {
}

void GraphicalBodyPart::updateAnimation(const std::chrono::milliseconds &elasped_time) {
    _AnimationCurrentTick += elasped_time;
    if (_AnimationCurrentTick > _AnimationDuration) {
        _AnimationCurrentTick = std::chrono::milliseconds(0);
    }
}

void GraphicalBodyPart::setSpriteRelativePosition(const Position &pos, Orientation dir) {
    sf::Sprite &tmp = getAnimationSprite(dir);
    tmp.setPosition(pos.x - (_canvas.width / 2), pos.y - (_canvas.height / 2));
}


