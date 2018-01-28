//
// Created by zouz on 12/01/18.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGER_HPP
#define LIFEISBORNE_RESSOURCEMANAGER_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

template <typename Obj>
class RessourceManager
{

public:
    RessourceManager() = default;
    ~RessourceManager() = default;

    std::shared_ptr<Obj> &store(const std::string &id, const Obj &&toStore)
    {
        std::shared_ptr<Obj> tmp(std::make_shared(toStore));
        return _data.emplace(std::make_pair(id, std::move(tmp))).first->second;
    }

    const std::shared_ptr<Obj> &get(const std::string &id)
    {
        return _data.at(id);
    }

    std::shared_ptr<Obj> &operator[](const std::string &id)
    {
        return *_data.at(id);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Obj>> _data;
};

#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
