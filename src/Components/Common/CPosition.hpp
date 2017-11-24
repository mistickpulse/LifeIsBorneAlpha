//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_POSITION_HPP
#define LIFEISBORNE_POSITION_HPP

#include "../AComponent.hpp"

class CPosition : public AComponent {
public:
    CPosition(const Position &pos) : AComponent(typeid(CPosition).name()), _pos(pos) {
    }


    ~CPosition() = default;

    void setPos(const Position &pos) {
        _pos = pos;
    }

    const Position &getPos() const {
        return _pos;
    }

private:

    Position _pos{0, 0};
};

#endif //LIFEISBORNE_POSITION_HPP
