//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_HP_HPP
#define LIFEISBORNE_HP_HPP

#include "../AComponent.hpp"

class CHp : public AComponent {
public:
   CHp(unsigned int max, unsigned int current):
           AComponent(typeid(CHp).name()), max(max), current(current){}
   ~CHp() override = default;

private:
    unsigned int max;
    unsigned int current;
};

#endif //LIFEISBORNE_HP_HPP
