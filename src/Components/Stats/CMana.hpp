//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_MANA_HPP
#define LIFEISBORNE_MANA_HPP

#include "../AComponent.hpp"

class CMana : public AComponent {
public:

   CMana(unsigned int max, unsigned int current):
           AComponent(typeid(CMana).name()), max(max), current(current){}
private:
    unsigned int max;
    unsigned int current;
};

#endif //LIFEISBORNE_MANA_HPP
