//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_POSITION_HPP
#define LIFEISBORNE_POSITION_HPP

#include "../AComponent.hpp"

class CPosition : public AComponent {
public:
    CPosition(): AComponent(typeid(CPosition).name()) {
    }
    ~CPosition() = default;
private:
};

#endif //LIFEISBORNE_POSITION_HPP
