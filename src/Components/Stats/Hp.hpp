//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_HP_HPP
#define LIFEISBORNE_HP_HPP

#include "../AComponent.hpp"

class Hp : public AComponent {
public:
   Hp(unsigned int max, unsigned int current):
           AComponent(typeid(Hp).name()), max(max), current(current){}
   ~Hp() override = default;

private:
    unsigned int max;
    unsigned int current;
};

#endif //LIFEISBORNE_HP_HPP
