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
    AInputController(AControlMapping *controllerMapping);

    virtual ~AInputController() = default;


public:
    virtual void update() = 0;

public:
    InputControllerType getControllerType() const;

    void changeControllerMap(AControlMapping *controllerMapping);

    GameInput getLastInput();

    void addInput(GameInput input);


protected:
    std::queue<GameInput> _inputs;
    InputControllerType _controllerType;
    AControlMapping *_mapKey;
};

#endif //LIFEISBORNE_AINPUTCONTROLLER_HPP
