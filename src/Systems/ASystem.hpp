//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_ASYSTEM_HPP
#define LIFEISBORNE_ASYSTEM_HPP

#include <chrono>
#include "../Entities/AEntity.hpp"
#include "SystemLore.hpp"

class ASystem {
public:
    explicit ASystem(const std::string &SystemId, SystemPriority prio, SystemState state = SystemState::INACTIVE) :
            SystemId(SystemId), _priority(prio), _state(state) {}

    ASystem() = delete;

    virtual ~ASystem() = default;

public:
    virtual void compute(std::vector<AEntity *> &entities, const std::chrono::milliseconds &) = 0;

    SystemPriority getPriority() const;

private:
    const std::string &SystemId;
    const SystemPriority _priority;
    SystemState _state;

};


#endif //LIFEISBORNE_ASYSTEM_HPP
