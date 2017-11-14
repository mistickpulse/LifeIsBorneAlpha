//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_MANA_HPP
#define LIFEISBORNE_MANA_HPP

#include "../AComponent.hpp"

class Mana : public AComponent {
public:

   Mana(unsigned int max, unsigned int current):
           AComponent(typeid(Mana).name()), max(max), current(current){}
private:
    unsigned int max;
    unsigned int current;
};

#endif //LIFEISBORNE_MANA_HPP
