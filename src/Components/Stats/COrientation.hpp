//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_CORIENTATION_HPP
#define LIFEISBORNE_CORIENTATION_HPP

#include "../AComponent.hpp"
#include "Orientation.hpp"


class COrientation : public AComponent {
public:
    COrientation() = delete;
    explicit COrientation(Orientation direction);
    ~COrientation() = default;

    Orientation getDirection() const {
        return _direction;
    }

private:
    Orientation _direction;
};

#endif //LIFEISBORNE_CORIENTATION_HPP
