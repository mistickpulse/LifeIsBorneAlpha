//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_AINPUTCONTROLLER_HPP
#define LIFEISBORNE_AINPUTCONTROLLER_HPP

#include <queue>
#include "../InputControllerType.hpp"
#include "../GameInput.hpp"
#include "../HitMaps/AControlMapping.hpp"

class AInputController {
public:
    explicit AInputController(AControlMapping *controllerMapping);

    virtual ~AInputController() = default;

public:
    virtual void update() = 0;

public:
    InputControllerType getControllerType() const;
    GameInput getLastInput();
    void changeControllerMap(AControlMapping *controllerMapping);
    void addInput(GameInput input);

protected:
    AControlMapping *_mapKey;
    InputControllerType _controllerType;
    std::queue<GameInput> _inputs;
};

#endif //LIFEISBORNE_AINPUTCONTROLLER_HPP
