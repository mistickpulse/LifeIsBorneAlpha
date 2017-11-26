//
// Created by zouz on 24/11/17.
//

#ifndef LIFEISBORNE_SYSANIMATION_HPP
#define LIFEISBORNE_SYSANIMATION_HPP

#include <unordered_map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <typeinfo>
#include "../ASystem.hpp"
#include "../../Components/Body/CGraphicalBody.hpp"
#include "../../Components/Common/CPosition.hpp"
#include "../../Components/Common/CDirection.hpp"

namespace {
    std::array<std::string, 3> ComponentHandled{
            typeid(CGraphicalBody).name(),
            typeid(CPosition).name(),
            typeid(CDirection).name()
    };
}

class SysAnimation : public ASystem {
public:
    explicit SysAnimation(sf::RenderWindow &win);

    ~SysAnimation() = default;

    void compute(std::vector<AEntity *> &entities, const std::chrono::milliseconds &elapsed);

    void _execute(std::unordered_map<std::string, AComponent *> ComponentToTreat, const std::chrono::milliseconds &el);


private:
    void __animate(std::unordered_map<std::string, AComponent *> &components, const std::chrono::milliseconds &el);

private:
    sf::RenderWindow &win;
};

#endif //LIFEISBORNE_SYSANIMATION_HPP
