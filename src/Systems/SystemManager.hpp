//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_SYSTEMMANAGER_HPP
#define LIFEISBORNE_SYSTEMMANAGER_HPP

#include <vector>
#include "ASystem.hpp"
#include "SystemLore.hpp"

class SystemManager {
public:
    SystemManager() = default;
    ~SystemManager() = default;

    void systemRegister(ASystem &newSys) {
        _systems.emplace_back(newSys);
    }

    void run(std::vector<AEntity> &ent) {
        for (auto &&i : _systems) {
           i.compute(ent);
        }
    }

private:
    std::vector<ASystem> _systems;
};

#endif //LIFEISBORNE_SYSTEMMANAGER_HPP