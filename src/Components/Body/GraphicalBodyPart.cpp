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

sf::Sprite *GraphicalBodyPart::getAnimationSprite(const std::string &AnimationType, Orientation bodyOrientation) {
    int offset = 0;

    BodyPartAnimation &bAnimation = _sprites[AnimationType];
    offset = (_AnimationCurrentTick / _AnimationTick) % (bAnimation[bodyOrientation].size());
    for (auto &i : bAnimation) {
        if (i.first == bodyOrientation) {
            return i.second[offset];
        }
    }
}

GraphicalBodyPart::GraphicalBodyPart(BodyPartAnimationType &SpriteSrc, BodyPartType type, const Size &canvasSize,
                                     const std::chrono::milliseconds &ADuration) :
        _sprites(SpriteSrc),
        _type(type),
        _canvas(canvasSize),
        _AnimationDuration(ADuration),
        _AnimationCurrentTick(0),
        _AnimationTick(0) {
}

void GraphicalBodyPart::updateAnimation(const std::chrono::milliseconds &elasped_time) {
    _AnimationCurrentTick += elasped_time;
    if (_AnimationCurrentTick > _AnimationDuration) {
        _AnimationCurrentTick = std::chrono::milliseconds(0);
    }
}

void GraphicalBodyPart::setSpriteRelativePosition(const Position &pos, Orientation dir) {
    sf::Sprite &tmp = *getAnimationSprite(AnimationType, dir);
    tmp.setPosition(pos.x - (_canvas.width / 2), pos.y - (_canvas.height / 2));
}

void GraphicalBodyPart::setAnimationType(const std::string &Atype) {
    _AnimationTick = std::chrono::milliseconds(0); // Aduration / vector sprite size;
}


