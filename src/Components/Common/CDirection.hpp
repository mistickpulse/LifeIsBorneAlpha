//
// Created by zouz on 24/11/17.
//

#ifndef LIFEISBORNE_CDIRECTION_HPP
#define LIFEISBORNE_CDIRECTION_HPP

#include "../Stats/Orientation.hpp"
#include "../AComponent.hpp"

class CDirection : public AComponent {
public:
    CDirection(Orientation dir) :
            AComponent(typeid(CDirection).name()),
            _direction(dir) {

    }

    ~CDirection() = default;

public:

    void setOrientation(Orientation dir) {
        _direction = dir;
    }

    Orientation getOrientation() const {
        return _direction;
    }

private:
    Orientation _direction;
};

#endif //LIFEISBORNE_CDIRECTION_HPP
