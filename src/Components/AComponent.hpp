//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_ACOMPONENT_HPP
#define LIFEISBORNE_ACOMPONENT_HPP

#include <string>

class AComponent {
public:
    explicit AComponent(const std::string &ComponentType):_type(ComponentType){}
    AComponent() = delete;
    virtual ~AComponent() = default;

    const std::string &getType() const {
       return _type;
    }
private:
    const std::string _type;
};

#endif //LIFEISBORNE_ACOMPONENT_HPP
